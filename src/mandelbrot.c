/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:20 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/19 14:34:16 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fractol *f, t_img *img, int x, int y, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	int		is_in_set;

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	if (n >= 0 && n <= (MAX_ITERATIONS / 2) - 1)
		my_mlx_pixel_put(img, x, y, 0x00003366);
	else if (n >= MAX_ITERATIONS / 2 && n <= MAX_ITERATIONS - 1)
		my_mlx_pixel_put(img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(img, x, y, 0x00CC3333);
}

void	draw_mandelbrot(t_fractol *f, t_img *img)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			mandelbrot(f, img, x, y, pr, pi);
		}
	}
}

void	init_mandel(void)
{
	t_img		img;
	t_fractol	f;

	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return ;
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Mandelbrot Set");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_mandelbrot(&f, &img);
	mlx_put_image_to_window(f.mlx, f.win, img.img, 0, 0);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, &close_win, &f);
	mlx_key_hook(f.win, &key_hooks, &f);
	// mlx_mouse_hook(f.win, &mouse_event, &mlx);
	mlx_loop(f.mlx);
	mlx_destroy_window(f.mlx, f.win);
}

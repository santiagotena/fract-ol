/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:38 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/19 23:12:55 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_fractol *f, t_img *img, int x, int y, double zr, double zi)
{
	int		n;
	double	tmp;

	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
	}
	if (n >= 0 && n <= (MAX_ITERATIONS / 2) - 1)
		my_mlx_pixel_put(img, x, y, 0x00003366);
	else if (n >= MAX_ITERATIONS / 2 && n <= MAX_ITERATIONS - 1)
		my_mlx_pixel_put(img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(img, x, y, 0x00CC3333);
}

void	draw_julia(t_fractol *f, t_img *img)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	mlx_clear_window(f->mlx, f->win);
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			julia(f, img, x, y, pr, pi);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, img->img, 0, 0);
}

void	init_julia(char **argv)
{
	t_fractol	f;
	t_img		img;

	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return ;
	f.f_name = *argv[1];
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	if (!ft_strncmp(argv[1], "julia", 6))
	{
		f.kr = ft_atod(argv[2]);
		f.ki = ft_atod(argv[3]);	
	}
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fractal");
	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	f.pimg = &img;
	draw_julia(&f, f.pimg);
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, &close_win, &f);
	mlx_key_hook(f.win, &key_hooks, &f);
	mlx_mouse_hook(f.win, &mouse_event, &f);
	mlx_loop(f.mlx);
}

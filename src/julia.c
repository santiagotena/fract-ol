/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:38 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 23:53:57 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	julia(t_fractol *f, t_img *img, int x, int y, double zr, double zi)
{
	int		n;
	double	tmp;
	int		is_in_set;

	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
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
}

void	init_julia(char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_fractol	f;

	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return ;
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	f.kr = ft_atod(argv[2]);
	f.ki = ft_atod(argv[3]);
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Julia Set");
	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_julia(&f, &img);
	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);
	mlx_hook(mlx.win, EVENT_CLOSE_BTN, 0, &close_win, &mlx);
	mlx_key_hook(mlx.win, &key_hooks, &mlx);
	// mlx_mouse_hook(mlx.win, &mouse_event, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_window(mlx.mlx, mlx.win);
}

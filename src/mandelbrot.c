/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:11:20 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/15 23:26:30 by stena-he         ###   ########.fr       */
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
	if (is_in_set == 1)
		my_mlx_pixel_put(img, x, y, 0x00000000);
	else
		my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_mandelbrot(t_fractol *f, t_img *img)
{
	int	x;
	int	y;
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

void	init_mandel()
{
	t_mlx		mlx;
	t_img		img;
	t_fractol 	f;

	// f.f_name = name;
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return ; 
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	f.kr = -0.77;
	f.ki = -0.09;
	mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "Fract'ol test");

	img.img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	draw_mandelbrot(&f, &img);

	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);

	mlx_loop(mlx.mlx);
}

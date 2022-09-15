// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   draw_fractal.c                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/09/13 22:09:02 by stena-he          #+#    #+#             */
// /*   Updated: 2022/09/15 22:59:04 by stena-he         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../fractol.h"

// void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// void	draw_fractal(t_fractol *f, t_img *img)
// {
// 	int	x;
// 	int	y;
// 	double	pr;
// 	double	pi;

// 	y = -1;
// 	while (++y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIDTH)
// 		{
// 			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
// 			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
// 			// if (!ft_strncmp(f->f_name, "mandelbrot", 11))
// 				// mandelbrot(f, img, x, y, pr, pi);
// 			// if (!ft_strncmp(f->f_name, "julia", 6))
// 				// julia(f, img, x, y, pr, pi);
// 		}
// 	}
// }

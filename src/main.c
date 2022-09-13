/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/13 23:05:18 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol 	f;
	t_data		img;

	if (argc < 2)
		// Error
	f.f_name = argv[1];
	f.mlx = mlx_init();
	if (f.mlx == NULL)
		return (0); 
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	f.kr = -0.77;
	f.ki = -0.09;
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol test");

	img.img = mlx_new_image(f.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	draw_fractal(&f, &img);

	mlx_put_image_to_window(f.mlx, f.win, img.img, 0, 0);

	
	mlx_loop(f.mlx);
}

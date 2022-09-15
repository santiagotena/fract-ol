/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/15 19:51:49 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_mlx		mlx;
	t_img		img;
	t_fractol 	f;

	if (argc < 2)
		// Error
	f.f_name = argv[1];
	mlx.mlx = mlx_init();
	if (mlx.mlx == NULL)
		return (0); 
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

	draw_fractal(&f, &img);

	mlx_put_image_to_window(mlx.mlx, mlx.win, img.img, 0, 0);

	
	mlx_loop(mlx.mlx);
}

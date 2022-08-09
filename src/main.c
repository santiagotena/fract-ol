/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/08/09 21:11:01 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		main(void)
{
	t_fractol f;

	f.mlx = mlx_init();
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;

	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol test");
	
	// draw_fractal(&f)
	mlx_loop(f.mlx);
}

// #include <unistd.h>
// #include "mlx.h"

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

// int		deal_key(int key, void *param)
// {
// 	ft_putchar('X');
// 	return (0);
// }

// int main()
// {
// 	void	*mlx_ptr;
// 	void	*win_ptr;

// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
// 	mlx_key_hook(win_ptr, deal_key, (void *)0);
// 	mlx_loop(mlx_ptr);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/08/10 01:24:44 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci)
{
	int		n;
	double	zr;
	double	zi;
	double	tmp;
	int		is_in_set;

	zr = 0;
	zi = 0;
	n = 0;
	is_in_set = 1;
	while (n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
		n ++;
	}
	if (is_in_set == 1)
		mlx_pixel_put(f->mlx, f->win, x, y, 0x000000);
	else
		mlx_pixel_put(f->mlx, f->win, x, y, 0xFFFFFF);
}

void	draw_fractal(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double 	pi;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			mandelbrot(f, x, y, pr, pi);
			x ++;
		}
		y ++;
	}
}

int		main(void)
{
	t_fractol f;

	f.mlx = mlx_init();
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;

	f.win = mlx_new_window(&f.mlx, WIDTH, HEIGHT, "Fract'ol test");
	
	draw_fractal(&f);
	mlx_loop(f.mlx);
	// mlx_destroy_window(&f.mlx, f.win);
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

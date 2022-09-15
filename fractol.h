/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:13:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/15 19:23:18 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

/* Parameters */
#define MAX_ITERATIONS 80
#define WIDTH 900
#define HEIGHT 900

/* Libraries */
//Std libraries
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

//Own libraries
# include "libraries/mlx/mlx.h"
# include "libraries/ft_printf/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"

//MLX
#include "mlx.h"

/* Structs */
//Fractal parameters
typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	char		*f_name;
	double		min_r;
	double 		max_r;
	double		min_i;
	double		max_i;
	double		kr;
	double		ki;
}				t_fractol;
//Images
typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/* Functions */
// Fractals
void	mandelbrot(t_fractol *f, t_data *img, int x, int y, double cr, double ci);
void	julia(t_fractol *f, t_data *img, int x, int y, double zr, double zi);

// Draw fractals
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_fractal(t_fractol *f, t_data *img);

#endif

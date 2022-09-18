/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:13:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 16:03:07 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Parameters */
# define MAX_ITERATIONS 80
# define WIDTH 900
# define HEIGHT 900

/* Libraries */
//Std libraries
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

//Custom libraries
# include "libraries/mlx/mlx.h"
# include "libraries/ft_printf/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"

/* Structs */
//MLX (new)
typedef struct s_mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

//Images (data)
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

//Fractal parameters 
typedef struct s_fractol
{
	char	*f_name;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	kr;
	double	ki;
}				t_fractol;

/* Functions */
// Fractals
void	mandelbrot(t_fractol *f, t_img *img, int x, int y, double cr, double ci);
void	julia(t_fractol *f, t_img *img, int x, int y, double zr, double zi);

// Help
void	print_help(void);

// Draw fractals
void	init_mandel(void);
void	init_julia(char **argv);

//Windows
int		close_win(t_mlx *data);
int		key_hooks(int keycode, t_mlx *data);

//Utils
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	ft_atod(char *arr);
int		close_win(t_mlx *data);


#endif

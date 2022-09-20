/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:13:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/20 21:21:17 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* Parameters */
# define MAX_ITERATIONS 255
# define WIDTH 900
# define HEIGHT 900

/* Keys */
# define EVENT_CLOSE_BTN 17
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

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
//Fractal parameters 
typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	char			*f_name;
	double			min_r;
	double			max_r;
	double			min_i;
	double			max_i;
	double			kr;
	double			ki;
	struct s_img	*pimg;
}				t_fractol;

typedef struct s_point {
	int		x;
	int		y;
	double	r;
	double	i;
}				t_point;

//Images (data)
typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/* Functions */
// Help
void	print_help(void);

// Draw fractals //
// Mandelbrot
void	init_mandelbrot(char **argv);
void	mandelbrot(t_img *img, int x, int y, double cr, double ci);
void	draw_mandelbrot(t_fractol *f, t_img *img);
// Julia
void	init_julia(char **argv);
void	julia(t_fractol *f, t_img *img, t_point *p);
void	draw_julia(t_fractol *f, t_img *img);

//Window Acrtions
int		close_win(t_fractol *data);
int		key_hooks(int keycode, t_fractol *data);
int		mouse_event(int keycode, int x, int y, t_fractol *f);

//Utils
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
double	ft_atod(char *arr);

#endif

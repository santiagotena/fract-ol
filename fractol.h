/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:13:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/12 22:17:54 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

//Parameters
#define MAX_ITERATIONS 80
#define WIDTH 900
#define HEIGHT 900

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

//Structs
typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	double		min_r;
	double 		max_r;
	double		min_i;
	double		max_i;
	double		kr;
	double		ki;
}				t_fractol;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 22:13:07 by stena-he          #+#    #+#             */
/*   Updated: 2022/08/10 00:44:43 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

#define MAX_ITERATIONS 80
#define WIDTH 900
#define HEIGHT 900

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <stdio.h>

# include "libraries/mlx/mlx.h"
# include "libraries/ft_printf/libft/libft.h"
# include "libraries/ft_printf/ft_printf.h"

#include "mlx.h"

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	double		min_r;
	double 		max_r;
	double		min_i;
	double		max_i;
}				t_fractol;

#endif

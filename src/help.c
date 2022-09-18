/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 22:44:22 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 13:26:23 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	print_help(void)
{
	ft_printf("/* Manual */\n\n");
	ft_printf("List of available fractals:\n");
	ft_printf("* Mandelbrot\n");
	ft_printf("./fractol mandelbrot\n");
	ft_printf("* Julia\n");
	ft_printf("./fractol julia <real_number> <imaginary_number>\n");
	ft_printf("e.g.: ./fractol julia -0.77 -0.09\n");
}

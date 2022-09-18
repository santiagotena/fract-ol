/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 13:54:46 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 15:57:04 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	ft_atod(char *arr)
{
	float	val;
	int		afterdot;
	float	scale;
	int		neg;

	val = 0;
	afterdot = 0;
	scale = 1;
	neg = 0;
	if (*arr == '-')
	{
		arr++;
		neg = 1;
	}
	while (*arr)
	{
		if (!ft_isdigit(*arr) && !(*arr == '.'))
		{
			ft_printf("Wait. That's illegal.\n\n");
			print_help();
			exit(0);
		}
		if (afterdot)
		{
			scale = scale / 10;
			val = val + (*arr - '0') * scale;
		}
		else
		{
			if (*arr == '.')
			afterdot++;
			else
			val = val * 10.0 + (*arr - '0');
		}
		arr++;
	}
	if (neg)
		return (-val);
	else
		return (val);
}

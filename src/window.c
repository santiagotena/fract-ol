/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:56:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 16:06:52 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int		close_win(t_mlx *data)
{
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	exit(0);
}

int		key_hooks(int keycode, t_mlx *data)
{
	if (keycode == 53)
		close_win(data);
	return (0);
}
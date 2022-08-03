/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/08/03 21:28:20 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	
	mlx_ptr = mlx_init();
	win_ptr = ml_new_window(mlx_ptr, 500, 500, );
	mlx_loop(mlx_ptr);	
}
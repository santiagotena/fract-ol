/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stena-he <stena-he@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:18:54 by stena-he          #+#    #+#             */
/*   Updated: 2022/09/18 15:42:12 by stena-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	if (argc < 2 || argc > 4)
	{
		print_help();
		return (0);
	}
	if (!ft_strncmp(argv[1], "mandelbrot", 11) && argc == 2)
		init_mandel();
	else if (!ft_strncmp(argv[1], "julia", 6) && argc == 4)
		init_julia(argv);
	else if (!ft_strncmp(argv[1], "help", 5))
		print_help();
	else
	{
		ft_printf("Wait. That's illegal.\n\n");
		print_help();
	}
	return (0);
}

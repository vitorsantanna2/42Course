/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:26:42 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 16:49:16 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	validations(int argc, char **argv, t_data *img)
{
	if (argc < 2)
		exit(0);
	else if (argc == 2)
	{
		if (ft_strcmp(ft_toupper(argv[1]), "MANDELBROT"))
			start_mandelbrot(img);
		else
			argument_invalid();
	}
	else if (argc == 4)
	{
		if (ft_strcmp(ft_toupper(argv[1]), "JULIA")
			&& ft_isdigit(argv[2]) && ft_isdigit(argv[3]))
		{
			img->name = "JULIA";
			start_julie(img, ft_atod(argv[2]), ft_atod(argv[3]));
		}
		else
			argument_invalid();
	}
	else
		argument_invalid();
}

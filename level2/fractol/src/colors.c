/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:49:27 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 18:34:09 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_rgb(int transparency, int red, int green, int blue)
{
	int	color;

	color = 0;
	color = color | (transparency << 24);
	color = color | (red << 16);
	color = color | (green << 8);
	color = color | blue;
	return (color);
}

int	color_by_iterations(int iterations)
{
	if (iterations % 8 == 7)
		return (ft_rgb(20, 0, 201, 191));
	else if (iterations % 8 == 6)
		return (ft_rgb(90, 0, 143, 0));
	else if (iterations % 8 == 5)
		return (ft_rgb(90, 75, 0, 130));
	else if (iterations % 8 == 4)
		return (ft_rgb(90, 0, 0, 255));
	else if (iterations % 8 == 3)
		return (ft_rgb(90, 0, 255, 255));
	else if (iterations % 8 == 2)
		return (ft_rgb(90, 0, 255, 127));
	else
		return (ft_rgb(255, 18, 76, 184));
}

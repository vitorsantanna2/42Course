/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:49:27 by jsantann          #+#    #+#             */
/*   Updated: 2022/10/15 11:09:39 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_rgb(int	transparency, int red, int green, int blue)
{
	int color;

	color = 0;
	color = color | (transparency << 24);
	color = color | (red << 16);
	color = color | (green << 8);
	color = color | blue;
	return (color);
}

int	color_by_iterations(int iterations)
{
	if (iterations >= 50)
		return (ft_rgb(20, 255, 255, 255));
	else if (iterations >= 45)
		return (ft_rgb(20, 18, 76, 184));
	else if (iterations >= 4)
		return (ft_rgb(55, 18, 76, 185));
	else if (iterations >= 3)
		return (ft_rgb(65, 18, 76, 184));
	else if (iterations >= 2)
		return (ft_rgb(75, 18, 76, 184));
	else if (iterations >= 1)
		return (ft_rgb(90, 18, 76, 184));
	else
		return (ft_rgb(255, 18, 76, 184));
}

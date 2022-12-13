/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 06:30:15 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 19:29:59 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_escape(t_data *img)
{
	int	iterations;

	iterations = 0;
	img->z.f = img->c.f;
	img->z.i = img->c.i;
	while (absolute_complex(img->z) < 2)
	{
		if (iterations == 300)
			break ;
		img->z = julia_complex(pow_complex(img->z), img);
		iterations++;
	}
	return (iterations);
}

void	draw_julia(t_data *img)
{
	img->vertical = 0;
	while (img->vertical < 900)
	{
		img->horizont = 0;
		while (img->horizont < 900)
		{
			img->c.i = (img->minim + img->vertical
				* (img->maxim - img->minim) / 900);
			img->c.f = img->minre + img->horizont
				* (img->maxre - img->minre) / 900;
			img->iterations = julia_escape(img);
			if (img->iterations == 150)
				my_mlx_pixel_insert(img, img->horizont,
					img->vertical, 0x000000);
			else
				my_mlx_pixel_insert(img, img->horizont,
					img->vertical, color_by_iterations(img->iterations));
			img->horizont++;
		}
		img->vertical++;
	}
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

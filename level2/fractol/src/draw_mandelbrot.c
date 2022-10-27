/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:29:28 by jsantann          #+#    #+#             */
/*   Updated: 2022/10/25 10:12:54 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
int	mandelbrot_escape(t_complex x)
{
	int iterations;
	t_complex	z;

	iterations = 0;
	z.f = 0;
	z.i = 0;
	while (absolute_complex(z) < 2)
	{
		if (iterations == 150)
			break;
		z = sum_complex(pow_complex(z), x);
		iterations++;
	}
	return (iterations);
}

void	draw_mandelbrot(t_data *img)
{
	while (img->vertical < 900)
	{
		img->horizont = 0;
		img->c.i = (img->minim + img->vertical * (img->maxim - img->minim) / 900);
		while (img->horizont < 900)
		{
			img->c.f = img->minre + img->horizont * (img->maxre - img->minre) / 900;
			img->iterations = mandelbrot_escape(img->c);
			if (img->iterations == 150)
			{
				my_mlx_pixel_insert(img, img->horizont, img->vertical, 0x000000);
			}
			else
				my_mlx_pixel_insert(img,img->horizont, img->vertical, color_by_iterations(img->iterations));
			img->z.f = 0;
			img->horizont++;
		}
		img->vertical++;
	}
	img->vertical = 0;
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img, 0, 0);
}

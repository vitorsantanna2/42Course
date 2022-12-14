/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:26:13 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 19:57:38 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	reset_hook(t_data *img)
{
	img->img = mlx_new_image(img->mlx_ptr, 900, 900);
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	if (!ft_strcmp(img->name, "JULIA"))
		draw_mandelbrot(img);
	else
		draw_julia(img);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		img->minim = img->minim * 1.1;
		img->maxim = img->maxim * 1.1;
		img->minre = img->minre * 1.1;
		img->maxre = img->maxre * 1.1;
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		reset_hook(img);
	}
	else if (keycode == 5)
	{
		img->minim = img->minim / 1.1;
		img->maxim = img->maxim / 1.1;
		img->minre = img->minre / 1.1;
		img->maxre = img->maxre / 1.1;
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		reset_hook(img);
	}
	return (0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		exit(0);
	}
	return (0);
}

int	close_hook(t_data *img)
{
	mlx_destroy_window(img->mlx_ptr, img->win_ptr);
	exit(0);
	return (0);
}

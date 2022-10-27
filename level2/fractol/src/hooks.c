/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:26:13 by jsantann          #+#    #+#             */
/*   Updated: 2022/10/25 08:35:28 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	reset_hook(t_data *img)
{
		img->img = mlx_new_image(img->mlx_ptr, 900, 900);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
		draw_mandelbrot(img);
		return (0);
}

int	mouse_hook(int keycode, int x, int y, t_data *img)
{
	(void)x;
	(void)y;
	if (keycode == 4)
	{
		img->zoom *= 1.1;
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		initializable_vars(img);
		reset_hook(img);
	}
	else if(keycode == 5)
	{
		img->zoom /= 1.1;
		mlx_clear_window(img->mlx_ptr, img->win_ptr);
		initializable_vars(img);
		reset_hook(img);
	}
	return (0);
}

int	close_hook(void)
{
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:40:46 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 20:31:16 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initializable_vars(t_data *img)
{
	img->minim = -1.5;
	img->maxim = 1.5;
	img->minre = -1.5;
	img->maxre = 1.5;
}

void	initializable_julia(t_data *img)
{
	img->minim = -2.0;
	img->maxre = 2.0;
	img->minre = -2.0;
	img->maxim = (img->maxre - img->minre) * 900 / 900 + img->minim;
}

void	start_mandelbrot(t_data *img)
{
	initializable_vars(img);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 900, 900, "Mandelbrot");
	img->img = mlx_new_image(img->mlx_ptr, 900, 900);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_mandelbrot(img);
}

void	start_julie(t_data *img, double x, double y)
{
	initializable_julia(img);
	img->j.f = x;
	img->j.i = y;
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 900, 900, "Julia");
	img->img = mlx_new_image(img->mlx_ptr, 900, 900);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_julia(img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (validations(argc, argv, &img))
	{
		mlx_hook(img.win_ptr, 17, 0, close_hook, &img);
		mlx_key_hook(img.win_ptr, key_hook, &img);
		mlx_mouse_hook(img.win_ptr, mouse_hook, &img);
		mlx_loop(img.mlx_ptr);
		return (free_memory(&img));
	}
	else
		return (0);
}

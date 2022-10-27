/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:40:46 by jsantann          #+#    #+#             */
/*   Updated: 2022/10/25 10:09:06 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initializable_vars(t_data *img)
{
	img->minim = -1.5 * img->zoom;
	img->maxim = 1.5 * img->zoom;
	img->minre = -1.5 * img->zoom;
	img->maxre = 1.5 * img->zoom;
}

void	start_fractol(t_data *img)
{
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, 900, 900, "Fractol");
	img->img = mlx_new_image(img->mlx_ptr, 900, 900);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	draw_mandelbrot(img);
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc <= 2 && argc !=1)
	{
		if (ft_strnstr(argv[1], "Mandelbrot", 10))
		{
			img.zoom = 1.0;
			initializable_vars(&img);
			start_fractol(&img);
			mlx_mouse_hook(img.win_ptr, mouse_hook, &img);
			mlx_hook(img.win_ptr, 17, 0, close_hook, &img);
			mlx_loop(img.mlx_ptr);
		}
		else
			argument_invalid();
	}
	else
	{
		argument_invalid();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:40:46 by jsantann          #+#    #+#             */
/*   Updated: 2022/09/27 18:12:55 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double absolute_complex(t_complex a)
{
	double abs;

	abs = sqrt(a.f * a.f + a.i * a.i);
	return (abs);
}

t_complex sum_complex(t_complex a, t_complex b)
{
	t_complex res;

	res.f = a.f + b.f;
	res.i = a.i + b.i;
	return (res);
}

t_complex pow_complex(t_complex a)
{
	t_complex res;

	res.f = a.f * a.f - a.i * a.i;
	res.i = 2 * a.f * a.i;
	return (res);
}

int	mandelbrot_escape(t_complex x)
{
	int iterations;
	t_complex	z;

	iterations = 0;
	z.f = 0;
	z.i = 0;

	while (iterations < 150)
	{
		if (absolute_complex(z) > 2)
		{
			return (1);
		}
		z = sum_complex(pow_complex(z), x);
		iterations++;
	}
	return (0);
}



int	main(void)
{
	t_complex x;
	void *mlx_ptr;
	void *win_ptr;
	int	counter;

	counter = 0;
	x.f = -2;
	x.i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 400, 400, "Hello world!");
	while (counter < 400)
	{
		x.f = x.f + 0.0075;
		if (mandelbrot_escape(x))
			mlx_pixel_put(mlx_ptr, win_ptr, 0, counter, 0x000000FF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, 0, counter, 0x00FFFFFF);
		counter++;
	}
	counter = 0;
	while (counter < 400)
	{
		x.f = x.f + 0.0075;
		if (mandelbrot_escape(x))
			mlx_pixel_put(mlx_ptr, win_ptr, counter, 200, 0x000000FF);
		else
			mlx_pixel_put(mlx_ptr, win_ptr, counter, 200, 0x00FFFFFF);
		counter++;	
	}
	mlx_loop(mlx_ptr);
}

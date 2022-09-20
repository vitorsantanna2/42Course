/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:40:46 by jsantann          #+#    #+#             */
/*   Updated: 2022/09/20 02:02:26 by jsantann         ###   ########.fr       */
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

int	main(void)
{
	data_t	data;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello World")) == NULL)
		return (EXIT_FAILURE);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}

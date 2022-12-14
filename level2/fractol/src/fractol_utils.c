/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:18:18 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 20:00:33 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	absolute_complex(t_complex z)
{
	double	abs;

	abs = sqrt(z.f * z.f + z.i * z.i);
	return (abs);
}

t_complex	sum_complex(t_complex first, t_complex second)
{
	t_complex	res;

	res.f = first.f + second.f;
	res.i = first.i + second.i;
	return (res);
}

t_complex	julia_complex(t_complex first, t_data *img)
{
	t_complex	res;

	res.f = first.f + img->j.f;
	res.i = first.i + img->j.i;
	return (res);
}

t_complex	pow_complex(t_complex z)
{
	t_complex	res;

	res.f = z.f * z.f - z.i * z.i;
	res.i = 2 * z.f * z.i;
	return (res);
}

void	argument_invalid(void)
{
	ft_printf("Error\n");
	ft_printf("Argumentos Válidos: \n");
	ft_printf("./fractol mandelbrot \n");
	ft_printf("./fractol julia 0 -0.8\n");
	exit(0);
}

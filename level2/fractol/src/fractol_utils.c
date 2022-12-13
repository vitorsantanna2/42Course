/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:18:18 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 19:27:27 by jsantann         ###   ########.fr       */
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
	ft_printf("Valids Arguments: \n'./fractol Mandelbrot\n./fractol julia num1 num2\nGood Inputs to Julie: \n./fractol Julia 0 -0.8'");
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:18:18 by jsantann          #+#    #+#             */
/*   Updated: 2022/10/25 09:58:39 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
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

t_complex	pow_complex(t_complex z)
{
	t_complex res;

	res.f = z.f * z.f - z.i * z.i;
	res.i = 2 * z.f * z.i;
	return (res);
}

void	argument_invalid(void)
{
	ft_printf("Argumentos Inválidos");
}

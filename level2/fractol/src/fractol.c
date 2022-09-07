/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:40:46 by jsantann          #+#    #+#             */
/*   Updated: 2022/09/07 18:03:23 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <math.h>

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

	res.f = a.f * a.f;
	res.i = a.i * a.f;
	return (res);
}

int	main(void)
{
	t_complex z;
	t_complex i;
	int	counter;

	counter = 50;
	z.f = 0;
	z.i = 0;
	while(counter-- > 0)
	{
		z.f = z.f * z.f + 1 + i;
		printf("%f\n", a.f);
	   if(a.f > 2)
	   {
		   printf("Infinite");
		   break;
	   }	   
	}
}

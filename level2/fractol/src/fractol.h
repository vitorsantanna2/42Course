/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:44:40 by jsantann          #+#    #+#             */
/*   Updated: 2022/09/19 15:29:39 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>


typedef struct	data_s
{
	void	*mlx_ptr;
	void	*mlx_win;
}			data_t;

typedef struct complex_number
{
	double	f;
	double	i;
}	t_complex;

#endif

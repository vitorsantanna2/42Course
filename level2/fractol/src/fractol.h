/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:44:40 by jsantann          #+#    #+#             */
/*   Updated: 2022/09/23 07:56:59 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

#include "../mlx/mlx.h"
#include <stdlib.h>
#include <math.h>


typedef struct	s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
}			t_data;

typedef struct s_complexnumber
{
	double	f;
	double	i;
}	t_complex;

#endif

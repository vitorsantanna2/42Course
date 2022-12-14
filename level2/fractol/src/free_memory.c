/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:19:09 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 20:46:30 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_memory(t_data *img)
{
	mlx_destroy_image(img->mlx_ptr, img->win_ptr);
	free(img);
	return (1);
}

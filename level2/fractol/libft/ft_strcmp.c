/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:55:34 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 16:50:41 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *src, char *dst)
{
	int	i;

	i = 0;
	if (ft_strlen(src) > ft_strlen(dst) || ft_strlen(src) < ft_strlen(dst))
		return (0);
	while (src[i])
	{
		if (src[i] == dst[i])
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}	

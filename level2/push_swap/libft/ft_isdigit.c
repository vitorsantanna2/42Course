/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:20:20 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/07 23:26:49 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_strlen(argv[i]) > 10)
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
			{
				if (ft_strlen(argv[i]) > 11)
						return (0);
				j++;
			}
			else if (argv[i][j] >= '0' && argv[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

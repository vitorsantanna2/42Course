/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:20:20 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/08 21:18:30 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(char **argv)
{
	int	i;
	int	j;
	int	signal;

	i = 1;
	while (argv[i])
	{
		j = 0;
		signal = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] == '-' || argv[i][j] == '+')
				&& argv[i][j + 1] && !signal)
			{
				signal = 1;
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

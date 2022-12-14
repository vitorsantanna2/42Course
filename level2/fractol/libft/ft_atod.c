/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 23:24:40 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 20:04:33 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	count_int(char *str)
{
	double	result;
	int		sign;
	int		i;

	i = 0;
	result = 0.0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		result = result * 10 + str[i++] - '0';
	result = result * sign;
	return (result);
}

double	ft_atod(char *str)
{
	double	right;
	double	result;
	int		i;

	result = count_int(str);
	right = 0.0;
	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (str[i] == '.' || str[i] == ',')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9' && str[i + 1])
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			right = right / 10.0 + (str[i--] - '0');
		result = result + (right / 10);
	}
	if (str[0] == '-')
		result = result * -1;
	return (result);
}

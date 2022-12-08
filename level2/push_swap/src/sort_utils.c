/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 16:24:53 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/07 23:24:58 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
		{
			return (0);
		}
		else
			temp = temp->next;
	}
	return (1);
}

int	is_repeated(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i + 1])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!ft_strncmp(argv[i], argv[j], 10))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long	ft_atol(char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
		result = result * 10 + str[i++] - '0';
	if (result > INT_MAX || result < INT_MIN)
	{
		ft_printf("Error");
		exit(-1);
	}
	return (result * sign);
}

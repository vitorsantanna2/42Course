/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:58:40 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/07 22:37:34 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	max_bits(t_list **stacka)
{
	t_list	*tmp;
	int		max;
	int		max_bits;

	tmp = *stacka;
	max = tmp->index;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	get_index(int n, int argc, char **argv)
{
	int	i;
	int	position;

	i = 1;
	position = 0;
	while (i < argc)
	{
		if (n > ft_atoi(argv[i]))
			position++;
		i++;
	}
	return (position);
}

void	radix(t_list **stacka, t_list **stackb)
{
	int		i;
	int		j;
	int		size;
	int		maxbits;

	i = 0;
	size = ft_lstsize(*stacka);
	maxbits = max_bits(stacka);
	while (i < maxbits)
	{
		j = 0;
		while (j++ < size)
		{
			if ((((*stacka)->index >> i) & 1) == 1)
				rotate(stacka, 'a');
			else
				push(stacka, stackb, 'b');
		}
		while (ft_lstsize(*stackb) != 0)
			push(stackb, stacka, 'a');
		i++;
	}
}

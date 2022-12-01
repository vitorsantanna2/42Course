/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 18:58:40 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/30 22:02:57 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	get_index(int n, int argc, char **argv)
{
	int	i;
	int position;

	i = 0;
	position = 0;
	while (i < argc - 1)
	{
		if (n > ft_atoi(argv[1 + i]))
		{
			position++;
		}
		i++;
	}
	return (position);
}

void radix(t_list **stacka, t_list **stackb)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *stacka;
	tmp2 = *stackb;

	(void)(tmp);
	(void)(tmp2);
	printf("teste");
}

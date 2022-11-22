/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_bigger_digit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:36:12 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/22 18:37:20 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	last_bigger_digit(t_list **stacka, t_list **stackb)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *stacka;
	tmp2 = *stackb;
	if (tmp->content < tmp->next->content
		&& tmp->content < ft_lstpenultimate(tmp)->content
		&& tmp->content < ft_lstlast(tmp)->content)
		push(&tmp, &tmp2, 'b');
	else if (tmp->next->content < ft_lstpenultimate(tmp)->content
			&& tmp->next->content < ft_lstlast(tmp)->content)
	{
		swap(&tmp, 'a');
		push(&tmp, &tmp2, 'b');
	}
	else if (ft_lstpenultimate(tmp)->content < ft_lstlast(tmp)->content)
	{
		rrotate(&tmp, 'a');
		rrotate(&tmp, 'a');
		push(&tmp, &tmp2, 'b');
	}
	else
	{
		rrotate(&tmp, 'a');
		push(&tmp, &tmp2, 'b');
	}
	*stacka = tmp;
	*stackb = tmp2;
}

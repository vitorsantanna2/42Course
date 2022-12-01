/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:22:05 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/24 18:52:08 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	take_little_big(t_list **stacka, t_list **stackb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stacka;
	tmp2 = *stackb;
	if (ft_lstlast(tmp)->content > tmp->next->content
		&& ft_lstlast(tmp)->content > tmp->next->next->content
		&& ft_lstlast(tmp)->content > tmp->next->next->next->content
		&& ft_lstlast(tmp)->content > tmp->content)
		rrotate(&tmp, 'a');
	else if (ft_lstpenultimate(tmp)->content > tmp->content
		&& ft_lstpenultimate(tmp)->content > tmp->next->content
		&& ft_lstpenultimate(tmp)->content > tmp->next->next->content)
	{
		rrotate(&tmp, 'a');
		rrotate(&tmp, 'a');
	}
	else
		take_little_big2(&tmp, &tmp2);
	push(&tmp, &tmp2, 'b');
	take_little_value(&tmp, &tmp2);
	*stacka = tmp;
	*stackb = tmp2;
}

void	take_little_big2(t_list **stacka, t_list **stackb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stacka;
	tmp2 = *stackb;
	if (tmp->next->next->content > tmp->next->content
		&& tmp->next->next->content > tmp->content)
	{
		rotate(&tmp, 'a');
		rotate(&tmp, 'a');
	}
	else if (tmp->next->content > tmp->content)
	{
		swap(&tmp, 'a');
	}
	*stacka = tmp;
	*stackb = tmp2;
}

void	sort_small_stack(t_list **stacka, t_list **stackb)
{
	take_little_big(stacka, stackb);
	sort_little_stack(stacka);
	push(stackb, stacka, 'a');
	push(stackb, stacka, 'a');
	rotate(stacka, 'a');
}

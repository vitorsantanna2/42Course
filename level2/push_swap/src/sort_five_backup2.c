/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:25:18 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/06 20:40:28 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

//First case are the conditions that first element of stackb is smallest than the last element of stacka
void	first_case(t_list **stacka, t_list **stackb)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *stacka;
	tmp2 = *stackb;
	if (tmp2->content < ft_lstlast(tmp)->content 
			&& tmp2->next->content < ft_lstlast(tmp)->content 
			&& tmp2->next->content > tmp->content 
			&& tmp2->content > ft_lstpenultimate(tmp)->content
			&& tmp2->next->content < ft_lstpenultimate(tmp)->content)
	{
		rrotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
		rotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		swap(&tmp, 'a');
	}
	else if (tmp2->content < ft_lstlast(tmp)->content
			&& tmp2->next->content < ft_lstlast(tmp)->content
			&& tmp2->next->content > tmp->content
			&& tmp2->next->content > tmp2->content
			&& tmp2->next->content < ft_lstpenultimate(tmp)->content)
	{
		swap(&tmp2, 'b');
		push(&tmp2, &tmp, 'a');
		swap(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
	}
	else if (tmp2->content < ft_lstlast(tmp)->content
			&& tmp2->next->content < ft_lstlast(tmp)->content
			&& tmp2->next->content > tmp->content
			&& tmp2->next->content > tmp2->content
			&& tmp2->content > ft_lstpenultimate(tmp)->content)
	{
		swap(&tmp2, 'b');
		rrotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
		rotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
	}
	else if (tmp2->content < ft_lstlast(tmp)->content
			&& tmp2->next->content < ft_lstlast(tmp)->content
			&& tmp2->next->content > tmp->content
			&& tmp2->content > ft_lstpenultimate(tmp)->content
			&& tmp2->next->content < tmp2->content)
	{
		rrotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
		rotate(&tmp, 'a');
		rotate(&tmp, 'a');
	}
	else if (tmp2->content < ft_lstlast(tmp)->content
			&& tmp2->next->content < ft_lstlast(tmp)->content
			&& tmp2->next->content > tmp->content
			&& tmp2->content < ft_lstpenultimate(tmp)->content
			&& tmp2->next->content < tmp2->content)
	{
		push(&tmp2, &tmp, 'a');
		swap(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		swap(&tmp, 'a');
	}
	/*else if (tmp2->content < tmp2->next->content
			&& tmp2>content < tmp->content)
	{

	}*/
	/*else if (tmp2->content < ft_lstlast(tmp)->content 
			&& tmp2->content > tmp->content)
	{
		push(&tmp2, &tmp, 'a');
		swap(&tmp, 'a');
		push(&tmp2, &tmp, 'a'); 
	}*/
	else if (tmp2->content < ft_lstlast(tmp)->content
			&& tmp2->next->content < tmp->content)
	{
		rrotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
		rotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
	}
	*stacka = tmp;
	*stackb = tmp2;
}

void	second_case(t_list **stacka, t_list **stackb)
{
	t_list *tmp;
	t_list *tmp2;

	tmp = *stacka;
	tmp2 = *stackb;

	if (tmp2->content > ft_lstlast(tmp)->content 
			&& ft_lstlast(tmp)->content > tmp2->next->content)
	{
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
	}
	else if (tmp2->content > ft_lstlast(tmp)->content)
	{
		swap(&tmp2, 'b');
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
		push(&tmp2, &tmp, 'a');
		rotate(&tmp, 'a');
	}
	*stacka = tmp;
	*stackb = tmp2;
}

void	sort_small_stack(t_list **stacka, t_list **stackb)
{
	push(stacka, stackb, 'b');
	push(stacka, stackb, 'b');
	sort_little_stack(stacka);
	first_case(stacka, stackb);
	//second_case(stacka, stackb);
	print_stack(*stacka);
	print_stack(*stackb);
}

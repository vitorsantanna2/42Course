/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:10:11 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/05 16:00:33 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push.h"

void	case1(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	if (temp->content > temp->next->content)
	{
		if (temp->content > ft_lstlast(*stack)->content
			&& temp->next->content < ft_lstlast(*stack)->content)
			rotate(stack, 'a');
		else
		{
			swap(stack, 'a');
			if (is_sorted(stack))
				return ;
			else if (temp->content > ft_lstlast(*stack)->content)
				rrotate(stack, 'a');
		}
	}
}

void	sort_little_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	case1(stack);
	if (is_sorted(stack))
		return ;
	if (temp->content > ft_lstlast(*stack)->content)
	{
		rrotate(stack, 'a');
	}
	else
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
}

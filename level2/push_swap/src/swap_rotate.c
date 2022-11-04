/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:04:39 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/03 19:28:55 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_list **stack)
{
	t_list *f_node;
	t_list *s_node;

	f_node = *stack;
	s_node  = f_node->next;
	f_node->next = s_node->next;
	s_node->next = f_node;
	*stack = s_node;
}

void	rotate(t_list **stack)
{
	t_list *f_node;
	t_list *s_node;
	t_list *l_node;

	f_node = *stack;
	s_node = f_node->next;
	l_node = ft_lstlast(*stack);
	l_node->next = f_node;
	f_node->next = NULL;
	*stack = s_node;
}

void	rrotate(t_list **stack)
{
	t_list *f_node;
	t_list *s_node;
	t_list *l_node;

	s_node = *stack;
	f_node = ft_lstlast(*stack);
	l_node = ft_lstpenultimate(*stack);
	f_node->next = s_node;
	l_node->next = NULL;
	*stack = f_node;
}

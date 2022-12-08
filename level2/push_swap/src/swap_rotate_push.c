/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 22:32:51 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/07 22:35:07 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap(t_list **stack, char s)
{
	t_list	*f_node;
	t_list	*s_node;

	f_node = *stack;
	s_node = f_node->next;
	f_node->next = s_node->next;
	s_node->next = f_node;
	*stack = s_node;
	if (s == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void	rotate(t_list **stack, char s)
{
	t_list	*f_node;
	t_list	*s_node;
	t_list	*l_node;

	f_node = *stack;
	s_node = f_node->next;
	l_node = ft_lstlast(*stack);
	l_node->next = f_node;
	f_node->next = NULL;
	*stack = s_node;
	if (s == 'a')
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
}

void	rrotate(t_list **stack, char s)
{
	t_list	*f_node;
	t_list	*s_node;
	t_list	*l_node;

	s_node = *stack;
	f_node = ft_lstlast(*stack);
	l_node = ft_lstpenultimate(*stack);
	f_node->next = s_node;
	l_node->next = NULL;
	*stack = f_node;
	if (s == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	push(t_list **src, t_list **dst, char s)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = *src;
	tmp = *dst;
	tmp3 = NULL;
	if (dst == NULL)
		tmp = ft_lstnew(tmp2->content, tmp2->index);
	else
	{
		tmp3 = ft_lstnew(tmp2->content, tmp2->index);
		ft_lstadd_front(&tmp, tmp3);
	}
	*dst = tmp;
	free(tmp2);
	tmp2 = tmp2->next;
	*src = tmp2;
	if (s == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}

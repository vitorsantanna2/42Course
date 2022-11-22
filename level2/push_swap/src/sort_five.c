/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:22:05 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/22 17:51:29 by jsantann         ###   ########.fr       */
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
		&& ft_lstlast(tmp)->content > ft_lstpenultimate(tmp)->content
		&& ft_lstlast(tmp)->content > tmp->content)
	{
		rrotate(&tmp, 'a');
		push(&tmp, &tmp2, 'b');
		last_bigger_digit(&tmp, &tmp2);
	}
	*stacka = tmp;
	*stackb = tmp2;
}

void	sort_small_stack(t_list **stacka, t_list **stackb)
{
	take_little_big(stacka, stackb);
	write(1, "Stack A\n", 8);
	print_stack(*stacka);
	write(1, "Stack B\n", 8);
	print_stack(*stackb);
}

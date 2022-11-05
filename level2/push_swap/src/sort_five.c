/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:22:05 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/05 15:55:49 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_small_stack(t_list **stacka, t_list **stackb)
{
	push(stacka, stackb, 'b');
	push(stacka, stackb, 'b');
	sort_little_stack(stacka);
	push(stackb, stacka, 'a');
	sort_little_stack(stacka);
	push(stackb, stacka, 'a');
	//print_stack(*stacka);
	//print_stack(*stackb);
}

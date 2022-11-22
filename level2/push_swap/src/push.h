/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:43:14 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/22 17:51:19 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PUSH_H

#include "../libft/libft.h"
#include <stdio.h>

void	print_stack(t_list *stack);
void	swap(t_list **stack, char s);
void	rotate(t_list **stack, char s);
void	rrotate(t_list **stack, char s);
void	push(t_list **src, t_list **dst, char s);
int		is_sorted(t_list **stack);
int		is_repeated(char **argv);
void	sort_small_stack(t_list **stacka, t_list **stackb);
void	sort_little_stack(t_list **stack);
void	last_bigger_digit(t_list **stacka, t_list **stackb);

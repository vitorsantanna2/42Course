/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 09:43:14 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/07 22:57:49 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../libft/libft.h"
# include <stdio.h>

# define INT_MAX  2147483647
# define INT_MIN -2147483648

void	print_stack(t_list *stack);
void	swap(t_list **stack, char s);
void	rotate(t_list **stack, char s);
void	rrotate(t_list **stack, char s);
void	push(t_list **src, t_list **dst, char s);
int		is_sorted(t_list **stack);
int		is_repeated(char **argv);
void	sort_small_stack(t_list **stacka, t_list **stackb);
void	sort_little_stack(t_list **stack);
void	take_little_value(t_list **stacka, t_list **stackb);
void	take_little_big(t_list **stacka, t_list **stackb);
void	take_little_big2(t_list **stacka, t_list **stackb);
void	radix(t_list **stacka, t_list **stackb);
int		get_index(int n, int argc, char **argv);
void	freestack(t_list **lst);
long	ft_atol(char *str);
#endif

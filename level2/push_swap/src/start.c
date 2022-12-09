/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:26:19 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/08 21:29:32 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	ft_printf("Ind | ");
	ft_printf("Val | ");
	ft_printf("Adr\n");
	while (temp)
	{
		ft_printf("%i   | ", temp->index);
		ft_printf("%i   | ", temp->content);
		ft_printf("%p\n", temp->content);
		temp = temp->next;
	}
	write(1, "\n", 1);
}

void	sort(int argc, t_list **stacka, t_list **stackb)
{
	if (is_sorted(stacka))
		freestack(stacka);
	else if (argc <= 4)
	{
		sort_little_stack(stacka);
		freestack(stacka);
	}
	else if (argc <= 6)
	{
		sort_small_stack(stacka, stackb);
		freestack(stacka);
	}
	else
	{
		radix(stacka, stackb);
		freestack(stacka);
	}
}

void	freestack(t_list **lst)
{
	t_list	*next;
	t_list	*stack;

	stack = *lst;
	while (stack)
	{
		next = stack->next;
		free(stack);
		stack = next;
	}
}

int	validations(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (!ft_isdigit(argv) || is_repeated(argv) || !is_bigger(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	else
		return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stacka;
	t_list	*stackb;
	int		position;

	if (!validations(argc, argv))
		return (0);
	else
	{
		i = 0;
		position = 0;
		while (i++ < argc - 1)
		{
			position = get_index(ft_atol(argv[i]), argc, argv);
			if (stacka == NULL)
				stacka = ft_lstnew(ft_atol(argv[i]), position);
			else
				ft_lstend(&stacka, ft_atol(argv[i]), position);
		}
		sort(argc, &stacka, &stackb);
	}
}

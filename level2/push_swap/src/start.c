/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:26:19 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/30 22:09:23 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	print_stack(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		ft_printf("%i", temp->content);
		ft_printf(" | %p\n", temp->content);
		temp = temp->next;
	}
	write(1, "\n", 1);
}

void	sort(int argc, t_list **stacka, t_list **stackb)
{
	if (argc <= 4)
		sort_little_stack(stacka);
	else if (argc <= 6)
		sort_small_stack(stacka, stackb);
	else
		radix(stacka, stackb);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stacka;
	t_list	*stackb;
	int	position;

	if (!ft_isdigit(argv) || is_repeated(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	else if (argc < 2)
		return (1);
	else
	{
		stacka = NULL;
		stackb = NULL;
		i = 1;
		position = 0;
		while (i < argc - 1)
		{
			position = get_index(ft_atoi(argv[1 + i]), argc, argv);
			if (stacka == NULL)
				stacka = ft_lstnew(ft_atoi(argv[1]), position);
			else
				ft_lstend(&stacka, ft_atoi(argv[1 + i++]), position);
		}
		i = 0;
		while (i < argc -1)
		{
			get_index(ft_atoi(argv[1 + i]), argc, argv);
			i++;
		}
		if (is_sorted(&stacka))
			return (1);
		sort(argc, &stacka, &stackb);
	}
}

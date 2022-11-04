/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 10:26:19 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/03 20:03:07 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"
void	print_stack(t_list *stack)
{
	t_list *temp;

	temp = stack;
	while(temp)
	{
		ft_printf("%i\n", temp->content);
		temp = temp->next;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	int i;
	t_list *stacka;
	//t_list *stackb;

	if (argc < 4)
		ft_printf("Error");
	else
	{
		stacka = ft_lstnew(ft_atoi(argv[1]));
		i = 1;
		while (i <  argc - 1)
		{
			ft_lstend(&stacka, ft_atoi(argv[1 + i]));
			i++;
		}
		print_stack(stacka);
		swap(&stack);
		print_stack(stack);
		rrotate(&stacka);
		print_stack(stacka);
	}
}

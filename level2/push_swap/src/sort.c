/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:10:11 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/03 20:18:17 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while(temp->next)
	{
		if (temp->content > temp->next->content)
			return 0;
		else
			temp = temp->next; 
	}
	return 1;
}

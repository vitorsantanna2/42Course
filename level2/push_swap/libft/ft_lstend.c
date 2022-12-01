/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:46:28 by jsantann          #+#    #+#             */
/*   Updated: 2022/11/30 22:01:40 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstend(t_list **lst, int content, int index)
{
	t_list *temp;

	temp = *lst;
	if (!temp)
	{
		return NULL;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = ft_lstnew(content, index);
	return (lst);
}

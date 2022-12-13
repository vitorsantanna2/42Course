/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:27:21 by jsantann          #+#    #+#             */
/*   Updated: 2022/12/13 14:37:32 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	toup(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

char	*ft_toupper(char *argv)
{
	int		i;
	char	*temp;

	i = 0;
	temp = malloc(sizeof(char) * ft_strlen(argv) + 1);
	while (argv[i])
	{
		temp[i] = toup(argv[i]);
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

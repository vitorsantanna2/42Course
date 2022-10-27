/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 02:23:57 by jsantann          #+#    #+#             */
/*   Updated: 2022/08/18 02:24:00 by jsantann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_words(const char *s, char c)
{
	size_t	i;
	size_t	n_words;
	size_t	k;

	i = 0;
	n_words = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (k != i)
			n_words++;
	}
	return (n_words);
}

static	size_t	count_latter(const char *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;
	size_t	n_words;

	i = 0;
	j = 0;
	n_words = count_words(s, c);
	ptr = (char **)ft_calloc(sizeof(char *), (n_words + 1));
	if (!ptr)
		return (NULL);
	while (s[i] != '\0' && j < n_words)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
		{
			ptr[j] = ft_substr(s, i, count_latter(s, c, i));
			if (!ptr[j++])
				return (NULL);
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (ptr);
}

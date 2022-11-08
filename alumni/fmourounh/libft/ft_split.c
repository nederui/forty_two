/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:58:08 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:17 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
		while (*s && *s == c)
			s++;
	}
	return (words);
}

static char	**assign_words(char **split, char const *s, char c, size_t words)
{
	char	*next_wd;
	size_t	i;
	size_t	len;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		next_wd = (char *)s;
		while (*next_wd && *next_wd != c)
			next_wd++;
		len = (size_t)(next_wd - s) + 1;
		split[i] = malloc(len * sizeof(char));
		ft_strlcpy(split[i], s, len);
		if (!split[i++])
		{
			free(split);
			return (NULL);
		}
		s = (char const *)next_wd;
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	words;

	if (!s)
		return (NULL);
	else if (!*s || !c)
	{
		split = malloc(sizeof(char *));
		split[0] = NULL;
	}
	else
	{
		words = ft_count_words(s, c);
		split = malloc((words + 1) * sizeof(char *));
		if (!split)
			return (NULL);
		split = assign_words(split, s, c, words);
		if (!split)
			return (NULL);
	}
	return (split);
}

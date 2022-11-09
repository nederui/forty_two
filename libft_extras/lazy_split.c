/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lazy_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:32:01 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 03:37:19 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_of_splits(char const *s, char c)
{
	size_t	i;
	size_t	splits;

	i = 0;
	splits = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			splits++;
		}
	}
	return (splits);
}

static char	*ft_space_jump(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	return (s + i);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted;
	size_t	splits;
	size_t	i;
	size_t	lenght;

	i = 0;
	splits = nbr_of_splits(s, c);
	splitted = (char **) malloc (sizeof(char *) * (splits + 1) + 1);
	if (splitted)
	{
		while (i < splits)
		{
			lenght = 0;
			while (((char *)s)[lenght] && ((char *)s)[lenght] != c)
				lenght++;
			((char *)s)[lenght] = '\0';
			splitted[i] = ft_space_jump(s, c);
			s = s + lenght + 1;
		}
		splitted[i] == NULL;
	}
	return (splitted);
}

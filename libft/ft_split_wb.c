/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:41:43 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/02 03:20:21 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_array(char const *str, char c)
{
	size_t	i;
	size_t	num_array;

	i = 0;
	num_array = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		if (str[i] != c && str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			num_array++;
		}
	}
	return (num_array);
}

char	*advance_str(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	s = s + i;
	return (s);
}

static char	**allfree(char **rtn_str)
{
	size_t	i;

	i = 0;
	while (rtn_str[i] != NULL)
	{
		free(rtn_str[i]);
		i++;
	}
	free(rtn_str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn_str;
	size_t	i;
	size_t	j;
	size_t	array;

	if (s == NULL)
		return (NULL);
	array = count_array(s, c);
	rtn_str = (char **) malloc (sizeof(char *) * (array + 1));
	if (rtn_str == NULL)
		return (NULL);
	j = 0;
	while (j < array)
	{
		i = 0;
		s = advance_str((char *)s, c);
		while (((char *)s)[i] != '\0' && ((char *)s)[i] != c)
			i++;
		rtn_str[j] = ft_substr(s, 0, i);
		if (rtn_str[j++] == NULL)
			return (allfree(rtn_str));
		s = s + i;
	}
	rtn_str[j] = NULL;
	return (rtn_str);
}

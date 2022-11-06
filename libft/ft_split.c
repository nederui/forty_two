/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:02:05 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/06 21:27:28 by nfilipe-         ###   ########.fr       */
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

static char	*ft_spacejump(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] == c)
		i++;
	s = s + i;
	return (s);
}

static char	**ft_malloc_check(char **splitted)
{
	size_t	i;

	i = 0;
	if (!splitted)
	{
		while (splitted[i] != NULL)
		{
			free(splitted[i]);
			i++;
		}
		free(splitted);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	index_s;
	size_t	splits;
	char	**splitted;

	i = 0;
	splits = nbr_of_splits(s, c);
	splitted = (char **) malloc (sizeof(char *) * (splits + 1));
	if (!splitted)
		return (NULL);
	while (i < splits)
	{
		index_s = 0;
		s = ft_spacejump((char *)s, c);
		while (((char *)s)[index_s] && ((char *)s)[index_s] != c)
			index_s++;
		splitted[i] = ft_substr(s, 0, index_s);
		i++;
		ft_malloc_check(splitted + i);
		s = s + index_s;
	}
	splitted[i] = NULL;
	return (splitted);
}

// 
// Parameters	s: The string to be split.
// 				c: The delimiter character.
// plitted = (char **) malloc(sizeof(char *) * splits + 1;
// Return value	The array of new strings resulting from the split.
// 				NULL if the allocation fails.
// 
// External ft:	malloc, free
// 
// Description	Allocates (with malloc(3)) and returns an array
// 				of strings obtained by splitting ’s’ using the
// 				character ’c’ as a delimiter. The array must end
// 				with a NULL pointer.
//

// int main(void)
// {
// 	char s[] = "  To be or not to   be that  is the question ";
// 	char **split_strings = ft_split(s, ' ');

// 	for (int i = 0; i < 9; i++)
// 		printf("%s\n", split_strings[i]);
// 	for (int i = 0; i < 9; i++)
// 		free(split_strings[i]);
// 	free(split_strings);
// 	return (0);
// }

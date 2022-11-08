/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:02:05 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 05:15:16 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Parameters	s: The string to be split.
// 				c: The delimiter character.
// 
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

#include "libft.h"
#include <stdio.h>

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

// static char	**ft_free(char **splitted)
// {
// 	size_t	i;

// 	i = 0;
// 	while (splitted[i] != NULL)
// 	{
// 		free(splitted[i]);
// 		i++;
// 	}
// 	free(splitted);
// 	return (NULL);
// }

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	lenght;
	size_t	splits;
	char	**splitted;

	if (!s)
		return (NULL);
	i = 0;
	splits = nbr_of_splits(s, c);
	splitted = (char **) malloc (sizeof(char *) * (splits + 1));
	if (s && splitted)
	{
		while (i < splits)
		{
			lenght = 0;
			s = ft_space_jump((char *)s, c);
			while (((char *)s)[lenght] && ((char *)s)[lenght] != c)
				lenght++;
			splitted[i] = ft_substr(s, 0, lenght);
			// if (splitted[i] == NULL)
			// 	return (ft_free(splitted));
			i++;
			s = s + lenght;
		}
		splitted[i] = NULL;
	}
	return (splitted);
}

// int main(void)
// {
// 	char *s= "      split       this for   me  !       ";
// 	char **split_strings = ft_split(s, ' ');

// 	for (int i = 0; i < 5; i++)
// 		printf("%s\n", split_strings[i]);
// 	for (int i = 0; i < 5; i++)
// 		free(split_strings[i]);
// 	free(split_strings);
// 	return (0);
// }

// ft_split is 4-part program.

// nbr_of_splits()
// we start by sweeping the original string (s) and counting how many
// times we need to split it. we do this by amounting the total number
// of character chunks which are not our delimiter (c);

// the first while loop checks for a situation where (c) is at the
// start of the string, and stops upon finding the first chunk.

// the second, within the condition of (c) having been found,
// increments(i) until it finds another delimenter; this determines
// our first split (split++);
/* code */
// we run this function for the full extent of the string (s), and 
// return the total number of splits;

// **ft_split()
// we allocate enough memory to accomodate our array of pointers,
// multiplying the size of a char pointer for the total of splits
// to be made.

// ft_spacejump()
// we sweep (s) once more until we find our first chunk; we return
// (s), with s[0] re-assigned to the position of the chunk just found;

// we then find the end of the chunk, by incrementing lenght, until
// we find another delimiter;

// and now that we now where its limits are, we are ready to save
// our first chunk to the first index of our array, by applying
// ft_substr() to (s) within those indexes [0 - lenght];

// ft_free()
// we increment the index of our array once, and make sure that we
// actually have allocated memory for our next chunk;
// if that's not the case, we make sure to free the memory of every 
// index of (**splitted), plus (**splitted) itself, to avoid any
// memory leak.

// if all went well with our malloc(), we re-assign s[0] to
// the respective end of the last copied chunk;

// we run this loop until it reaches the total number of splits
// to be made; in other words, we copied the last chunk;

// lastly, we terminate (**splitted) with a NULL pointer, at its
// last index; 

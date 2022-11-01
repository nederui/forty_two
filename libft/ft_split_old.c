/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:40:51 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/01 16:26:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	nbr_of_splits(char const *s, char c)
{
	size_t	i;
	size_t	i_2;
	size_t	len;
	size_t	splits;
	
	i = 0;
	splits = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(&s[i], c) == NULL)
				break;
			i++;
		}
		i_2 = i;		
		while (i < len)
		{
			if (ft_strchr(&s[i], c) != NULL)
				break;
			i++;
		}
		if (i > i_2)
			splits++;;
	}
	return (splits);
}


char **ft_split(char const *s, char c)
{
	size_t	i;
	size_t	i_2;
	size_t	i_3;
	size_t	len;
	size_t	splits;
	char **splitted;
	char	buffer[16384];
	size_t	to_allocate;
	
	i = 0;
	i_2 = 0;
	i_3 = 0;
	len = ft_strlen(s);
	splits = nbr_of_splits(s, c);
	splitted = malloc(sizeof(char *) * splits);
	to_allocate = sizeof(char) * (ft_strlen(buffer) + 1);
	while (i < len)
	{
		while (i < len)
		{
			if (ft_strchr(&s[i], c) == NULL)
				break;
			i++;
		}
		while (i < len)
		{
			if (ft_strchr(&s[i], c) != NULL)
				break;
			buffer[i_2] = s[i];
			i++;
			i_2++;
		}
		if (i_2 > 0)
		{
			buffer[i_2] = '\0';
			splitted[i_3] = malloc(to_allocate);
			splitted[i_3] = ft_strdup(buffer);
			i_3++;
		}
	}
	return (splitted);
}

int main(void)
{
	char s[] = "To, be, or, not, to be, that, is, the, question.";
	char **split_strings = ft_split(s, ',');

	for (int i = 0; i < 3; i++)
		printf("%s\n", split_strings[i]);
	for (int i = 0; i < 3; i++)
		free(split_strings[i]);
	
	free(split_strings);
	
	return (0);
}

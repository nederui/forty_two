/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:22:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/30 02:15:40 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int	ft_findnewline(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line)
	{
		if (line[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

int	ft_strlen(const char *string)
{
	int	l;

	l = 0;
	while (string[l] && string[l] != '\n')
		++l;
	if (string[l] == '\n')
		++l;
	return (l);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		i_s2;

	if (!s2)
		return (NULL);
	string = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (string)
	{
		i = -1;
		i_s2 = i;
		while (++i < ft_strlen(s1))
			string[i] = s1[i];
		while (++i_s2 < ft_strlen(s2))
			string[i + i_s2] = s2[i_s2];
		string[i + i_s2] = 0;
	}
	free(s1);
	return (string);
}

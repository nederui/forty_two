/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:32:06 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/07 17:16:22 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_freebuffer(char *buffer, int fd)
{
	int	i;
	
    if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
	i = 0;
	while (buffer[i])
	{
		buffer[i] = 0;	
		++i;
	}
	return (NULL);
}

int	ft_strlen_gnl(const char *string)
{
	int	l;

	l = 0;
	if (!string)
		return (0);
	while (string[l] && string[l] != '\n')
		++l;
	if (string[l] == '\n')
		++l;
	return (l);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		i_s2;

	if (!s2)
		return (NULL);
	string = (char *) malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (string)
	{
		i = -1;
		i_s2 = i;
		while (++i < ft_strlen_gnl(s1))
			string[i] = s1[i];
		while (++i_s2 < ft_strlen_gnl(s2))
			string[i + i_s2] = s2[i_s2];
		string[i + i_s2] = 0;
	}
	free(s1);
	return (string);
}

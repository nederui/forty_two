/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:32:06 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 17:13:24 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*string;
	int		i;
	int		i_b;

	if (!buffer)
		return (NULL);
	string = (char *) malloc(ft_strlen_gnl(line) + ft_strlen_gnl(buffer) + 1);
	if (string)
	{
		i = -1;
		i_b = i;
		while (++i < ft_strlen_gnl(line))
			string[i] = line[i];
		while (++i_b < ft_strlen_gnl(buffer))
			string[i + i_b] = buffer[i_b];
		string[i + i_b] = 0;
	}
	free(line);
	return (string);
}

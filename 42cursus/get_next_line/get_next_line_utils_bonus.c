/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:32:06 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/10 15:35:59 by nfilipe-         ###   ########.fr       */
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
	int	len;

	len = 0;
	if (!string)
		return (0);
	while (string[len] && string[len] != '\n')
		++len;
	if (string[len] == '\n')
		++len;
	return (len);
}

char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*string;
	int		i;
	int		i_b;
	int		len_line;
	int		len_buf;

	if (!buffer)
		return (NULL);
	len_line = ft_strlen_gnl(line);
	len_buf = ft_strlen_gnl(buffer);
	string = malloc(sizeof string * len_line + len_buf + 1);
	if (!string)
		return (NULL);
	i = -1;
	i_b = i;
	while (++i < len_line)
		string[i] = line[i];
	while (++i_b < len_buf)
		string[i + i_b] = buffer[i_b];
	string[i + i_b] = 0;
	free(line);
	return (string);
}

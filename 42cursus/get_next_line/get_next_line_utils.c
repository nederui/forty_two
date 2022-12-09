/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:22:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:17:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_freebuffer(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		buffer[i] = 0;
		i++;
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

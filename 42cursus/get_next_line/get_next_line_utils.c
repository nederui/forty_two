/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:22:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/13 15:35:41 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

// sets every index of 'buffer' to 0, in case of read() returnig an error;
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

/*
a variation of ft_strlen(), to measure the lenght of a string when reaching
'\0' or '\n'. though, the latter is included in the string;
*/
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

/*
a variation of ft_strjoin(), which makes use of ft_strlen_gnl() to concatenate
'buffer' to 'line' only up to either the '\0' or the '\n' characters; it returns
the new 'line' and makes sure the previous form of 'line' is free'd;
*/
char	*ft_strjoin_gnl(char *line, char *buffer)
{
	char	*newline;
	int		i;
	int		i_b;
	int		len_l;
	int		len_buf;

	if (!buffer)
		return (NULL);
	len_l = ft_strlen_gnl(line);
	len_buf = ft_strlen_gnl(buffer);
	newline = malloc(sizeof newline * len_l + len_buf + 1);
	if (!newline)
		return (NULL);
	i = -1;
	i_b = i;
	while (++i < len_l)
		newline[i] = line[i];
	while (++i_b < len_buf)
		newline[i + i_b] = buffer[i_b];
	newline[i + i_b] = 0;
	free(line);
	return (newline);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:31:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:32:23 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"
#include <unistd.h>
#include <stdio.h>

/*
buffer[FOPEN_MAX][BUFFER_SIZE + 1]: uninitialized data (every index = 0);

as third condition, reading will only happen if flag != 0 and the buffer is
empty; this way we avoid overlapping previously stored content;
*/
char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;
	int			i_0;

	if (BUFFER_SIZE < 1 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
		return (ft_freebuffer(buffer[fd], fd));
	line = NULL;
	flag = 0;
	while (!flag && (buffer[fd][0] || (read(fd, buffer[fd], BUFFER_SIZE) > 0)))
	{
		i = 0;
		i_0 = 0;
		line = ft_strjoin_gnl(line, buffer[fd]);
		while (buffer[fd][i])
		{
			if (flag)
				buffer[fd][i_0++] = buffer[fd][i];
			if (buffer[fd][i] == '\n')
				flag = 1;
			buffer[fd][i++] = 0;
		}
	}
	return (line);
}

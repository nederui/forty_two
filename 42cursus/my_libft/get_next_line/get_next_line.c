/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:31:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/24 17:26:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <unistd.h>
#include <stdio.h>

/*
reads the text file pointed to by the file descriptor, one line at a time; 
returs the line that was read (including the '\n' character), or NULL if there
is nothing else to read or if an error occurred;

buffer[FOPEN_MAX][BUFFER_SIZE + 1]: uninitialized data (every index = 0);

[FOPEN_MAX]: the maximum number of files that can be opened simultaneously;

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

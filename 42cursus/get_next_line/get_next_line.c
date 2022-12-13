/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:28:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/13 15:49:33 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

/*
reads the text file pointed to by the file descriptor, one line at a time; 
returs the line that was read (including the '\n' character), or NULL if there
is nothing else to read or if an error occurred;

buffer[BUFFER_SIZE + 1]: uninitialized data (every index = 0);

as third condition, reading will only happen if flag != 0 and the buffer is
empty; this way we avoid overlapping previously stored content;
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			i;
	int			i_0;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ft_freebuffer(buffer));
	line = NULL;
	flag = 0;
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		i = 0;
		i_0 = 0;
		line = ft_strjoin_gnl(line, buffer);
		while (buffer[i])
		{
			if (flag)
				buffer[i_0++] = buffer[i];
			if (buffer[i] == '\n')
				flag = 1;
			buffer[i++] = 0;
		}
	}
	return (line);
}

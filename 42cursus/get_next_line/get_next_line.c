/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:28:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/30 02:14:58 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
//
#include <stdio.h>
#include <stdlib.h>

// buffer[BUFFER_SIZE + 1]: uninitialized data (every index = 0)

// as a second condition, read will only happen if buffer is empty
// this way we avoid overlapping its content
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			flag;
	int			aft;
	int			bef;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	line = NULL;
	flag = 0;
	printf("before loop\n");
	while (!flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		bef = 0;
		aft = 0;
		printf("before join\n");
		line = ft_strjoin(line, buffer);
		printf("after join\n");
		while (buffer[bef])
		{
			printf("inside while\n");
			if (flag)
				buffer[aft++] = buffer[bef];
			if (buffer[bef] == '\n')
				flag = 1;
			buffer[bef++] = 0;
		}
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;

	s = get_next_line(fd);
	fd = open("./file.txt", O_RDONLY);
	printf("line: %s", s);
	// printf("line: %s", s);
	// printf("line: %s", s);
	close(fd);
	free(s);
	return (0);
}

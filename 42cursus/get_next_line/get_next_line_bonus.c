/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:31:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/05 18:07:01 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

/*
buffer[FOPEN_MAX][BUFFER_SIZE + 1]: uninitialized data (every index = 0);

as third condition, reading will only happen if flag != 0 and the buffer is empty;
this way we avoid overlapping previously stored content;
*/
char	*get_next_line(int fd)
{
	char		*line;
	char static	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	int			flag;
	int			i;
	int			i_0;

	if (BUFFER_SIZE < 1 || fd > FOPEN_MAX || read(fd, 0, 0) < 0)
        return(ft_freebuffer(buffer[fd], fd));
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

// int	main(void)
// {
// 	int		fd;
//     int     fd_2;
//     int     fd_3;
// 	char	*s;

// 	fd = open("./file.txt", O_RDONLY);
//     fd_2 = open("./file2.txt", O_RDONLY);
//     fd_3 = open("./file3.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("line: %s", s);
// 	s = get_next_line(fd_2);
// 	printf("line: %s", s);
// 	s = get_next_line(fd_3);
// 	printf("line: %s", s);
// 	s = get_next_line(fd);
// 	printf("line: %s", s);
// 	close(fd);
//     close(fd_2);
//     close(fd_3);
// 	free(s);
// 	return (0);
// }

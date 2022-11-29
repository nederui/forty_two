/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/29 04:17:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	read_and_save(char *line);

char	*get_next_line(int fd)
{
	static char	*line;
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		i = 0;
		while (line && line[i])
		{
			line[i] = 0;
			++i;
		}
		return (NULL);
	}
	ft_read_and_save(line);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*s;

	s = get_next_line(fd);
	fd = open("./file.txt", O_RDONLY);
	printf("line: %s", s);
	printf("line: %s", s);
	printf("line: %s", s);
	close(fd);
	free(s);
	return (0);
}

/* 
Parameters fd:		The file descriptor to read from

Return value		Read line: correct behavior
					NULL: there is nothing else to read, or an error
					occurred
					
External functs.	read, malloc, free

Description			Write a function that returns a line read from a
					file descriptor

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 00:00:04 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static char	pouch[BUFFER_SIZE];
	int			lenght;
	char		*line;

	while (ft_strchr(pouch, '\n') == 0)
	{
		read(fd, buffer, BUFFER_SIZE);
		ft_strlcat(pouch, buffer, 50);
	}
	if (ft_strchr(pouch, '\n') != 0)
	{
		lenght = (ft_strchr(pouch, '\n') - pouch);
		line = ft_substr(pouch, 0, lenght + 1);
		// ft_memmove(pouch, pouch + lenght + 1, BUFFER_SIZE);
		return (line);
	}
	return (NULL);
}

int	main(void)
{
	int		fd;

	fd = open("./file.txt", O_RDONLY);
	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	close(fd);
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

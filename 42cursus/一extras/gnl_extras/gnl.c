/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 00:00:39 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 02:59:44 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// char	*ft_clean_up(char *pouch, int lenght)
// {
// 	pouch = ft_substr(pouch, lenght, ft_strlen(pouch + lenght));
// 	return (pouch);
// }

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*pouch;
	char		*line;
	int			lenght;
	int			len;

	if (!pouch)
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		pouch = (char *) malloc(BUFFER_SIZE + 1);
		ft_memmove(pouch, buffer, BUFFER_SIZE);
		pouch[BUFFER_SIZE] = '\0';
	}
	if (pouch)
	{
		while (*buffer != 0)
		{
			if (ft_strchr(pouch, '\n') != 0)
			{
				lenght = (ft_strchr(pouch, '\n') - pouch);
				line = ft_substr(pouch, 0, lenght + 1);
				//ft_memset(pouch, 0, lenght);
				//ft_memmove(pouch, pouch + lenght + 1, BUFFER_SIZE);
				pouch = pouch + lenght + 1;
				return (line);
			}
			read(fd, buffer, BUFFER_SIZE);
			buffer[BUFFER_SIZE] = '\0';
			pouch = ft_strjoin(pouch, buffer);
		}
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
	printf("line: %s", get_next_line(fd));
	close(fd);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_fd_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 20:55:57 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/27 22:27:35 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char	*read_this_file(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];

	read(fd, buffer, BUFFER_SIZE);
	// buffer[BUFFER_SIZE] = '\0';
	return (buffer);
}

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("./file.txt", O_RDONLY);
	buffer = read_this_file(fd);
	close(fd);
	printf("buffer: %s\n", buffer);
	int i = 0;
	while (buffer[i] != '\0')
	{
		putchar(buffer[i]);
		i++;
	}
	if (buffer[i] == '\0')
		write(1, "\0", 2);
	return (0);
}

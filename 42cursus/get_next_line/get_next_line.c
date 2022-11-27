/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/25 19:21:16 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	static char	*n;
	char		*line;
	static char	*buffer;
	size_t		diff;
	void		*buffer_file;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	if (ft_strchr(buffer, '\n') > 0)
	{
		n = ft_strchr(buffer, '\n');
		diff = ft_strlen(buffer) - ft_strlen(n),
		line = (char *) malloc(diff + 1);
		if (!line)
			return (NULL);
		ft_memmove(line, buffer, diff);
		line[diff] = '\n';
		ft_memmove(buffer, n + 1, diff);
		return (line);
	}
	
	while (read(fd, buffer_file, BUFFER_SIZE) > 0)
	{
		ft_memmove(buffer, &buffer_file, BUFFER_SIZE);
		line[BUFFER_SIZE] = '\0';
		buffer_file++;
	}
	return (NULL);
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

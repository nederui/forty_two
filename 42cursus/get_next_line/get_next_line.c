/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/23 11:02:44 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	size_t		n;
	char		*line;
	static char	*buffer;
	static char	*pouch;
	size_t		pouch_lenght;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (read(fd, *buffer, BUFFER_SIZE) > 0)
	{
		ft_memmove(pouch, &buffer, BUFFER_SIZE);
		line[BUFFER_SIZE] = '\0';
		if (ft_strchr(buffer, '\n') > 0)
		{
			n = ft_strchr(buffer, '\n');
			ft_memmove(line, buffer, buffer - n);
			ft_memmove(buffer, buffer + n, n);
			line = (char *) malloc(ft_strlen(pouch) + 1);
			if (line)
				return (line);
		}
		buffer++;
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

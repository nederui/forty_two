/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/22 23:50:47 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

char	*get_next_line(int fd)
{
	size_t		i;
	char		*line;
	static char	*stash;

	i = 0;
	stash = char *malloc(sizeof(buffer) + 1);
	if (stash)
	{
		while (buffer)
		{
			read(fd, *buffer, bytes);
			ft_memmove(stash, buffer, bytes);
			if (ft_strchr(stash, '\n'))
			{
				ft_memmove(line, stash, );
				ft_memmove(stash, stash + i, );
			}
		}
	}
	return (line);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/29 08:40:29 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_find_newline(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line)
	{
		if (line[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*string;
	size_t		i;
	size_t		i_s2;

	if (!s2)
		return (NULL);
	string = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (string)
	{
		i = 0;
		i_s2 = i;
		while (i < ft_strlen(s1))
		{
			string[i] = s1[i];
			i++;
		}
		while (i_s2 < ft_strlen(s2))
		{
			string[i + i_s2] = s2[i_s2];
			i_s2++;
		}
		string[i + i_s2] = '\0';
	}
	// free(s1); ?
	return (string);
}

void	ft_read_and_save(char *line, int fd)
{
	size_t	bytes_read; // static ? or only purpose is to check EOF ?
	char	*buffer[BUFFER_SIZE + 1];
	
	// bytes_read = 1; ?
	while (!ft_find_newline(line) && bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer); // ft_memcpy() ?
		if (!line) // free buffer before return ; ?
			return ;
	}
	// return line (all char before '\n')
	// clean line (char already returned, including '\n')
	free(buffer);
}

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
	if(!line)
		line = NULL;
	ft_read_and_save(line, fd);
	if (!line)
		return (NULL);
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

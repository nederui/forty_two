/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_alpha.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:50:53 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 17:21:19 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// appends the content of buffer to pouch's tail

void	ft_add_to_pouch(char *pouch, char *buffer, int char_read)
{
	int	i;

	i = 0;
	if (!pouch)
	{
		pouch = (char *) malloc(sizeof(char) * (char_read + 1));
		if (!pouch)
			return ;
		while (buffer[i] && i < char_read)
		{
			pouch[i] = buffer[i];
			i++;
		}
		pouch[i] = '\0';
		printf("%s", pouch);
	}
	else
	{
		pouch = ft_strjoin(pouch, buffer);
		if (!pouch)
			return ;
	}
}

// uses read() to add characters to the pouch
void	ft_read_and_save(int fd, char *pouch, int char_read)
{
	char	*buffer;

	while (!ft_newline_finder(pouch) && char_read != 0)
	{
		buffer = (char *) malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = (int)read(fd, buffer, BUFFER_SIZE);
		if ((!pouch && char_read == 0) || char_read == -1)
		{
			free(buffer);
			return ;
		}
		buffer[char_read] = '\0';
		ft_add_to_pouch(pouch, buffer, char_read);
		free (buffer);
	}
}

// extracts all characters from pouch and stores them in 'line'
// stopping after the first '\n' it encounters
// void	ft_extract_line(char *pouch, char *line)
// {
// 	int	i;
// 	int	i_2;

// 	if (!pouch)
// 		return ;
// 	ft_line_generator(line, pouch);
// }

// clears the characters in 'pouch' that have already been returned
// void	ft_clear_pouch()
// {}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pouch;
	int			char_read;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	pouch = NULL;
	char_read = 1;
	ft_read_and_save(fd, pouch, char_read);
	if (!pouch)
		return (NULL);
	ft_extract_line(pouch, line);
	ft_clear_pouch(pouch);
	return (line);
}

int	main(void)
{
	int		fd;

	fd = open("./file.txt", O_RDONLY);
	printf("line: %s", get_next_line(fd));
	// printf("line: %s", get_next_line(fd));
	// printf("line: %s", get_next_line(fd));
	// printf("line: %s", get_next_line(fd));
	close(fd);
	return (0);
}

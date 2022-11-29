/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_beta.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:04:58 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 20:55:07 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dst);
}

// char	*ft_strdup(const char *s1)
// {
// 	char	*string;
// 	size_t	len_s1;

// 	len_s1 = ft_strlen((char *)s1);
// 	string = (char *) malloc(len_s1 + 1);
// 	if (string)
// 	{
// 		ft_memcpy(string, s1, len_s1);
// 		string[len_s1] = '\0';
// 	}
// 	return (string);
// }

int	ft_find_newline(char *pouch)
{
	int	i;

	if (!pouch)
		return (0);
	i = 0;
	while (pouch)
	{
		if (pouch[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

ft_clear_pouch(temp_pouch)
{
	char	*pouch;
	
	if (!temp_pouch)
		return ;
	while (temp_pouch[i] != '\n')
	{
		
	}
	
}

void	ft_extract_line(char *pouch, char *line)
{
	int	line_len;

	if (!pouch)
		return (0);
	line_len = 1;
	while (pouch[line_len] != '\n')
		++line_len;
	line = (char *) malloc(line_len + 1);
	if (!line)
		return ;
	ft_memcpy(line, pouch, line_len);
	line[line_len] = '\0';
}

void	ft_add_to_pouch(char *temp_pouch, char *buffer, size_t char_read)
{
	char	*pouch;
	size_t	pouch_len;

	pouch_len = ft_strlen(temp_pouch);
	pouch = (char *) malloc(pouch_len + char_read + 1);
	if (!pouch)
		return ;
	ft_memcpy(pouch, temp_pouch, pouch_len);
	ft_memcpy(pouch + pouch_len, buffer, char_read);
	pouch[pouch_len + char_read] = '\0';
	free(temp_pouch);
}

// void	ft_add_to_pouch(char *pouch, char *buffer, size_t char_read)
// {
// 	char	*temp_pouch;
// 	size_t	pouch_len;

// 	temp_pouch = ft_strdup(pouch);
// 	if (!temp_pouch)
// 		return ;
// 	pouch_len = ft_strlen(pouch);
// 	free(pouch);
// 	pouch = (char *) malloc(pouch_len + char_read + 1);
// 	if (!pouch)
// 		return ;
// 	ft_memcpy(pouch, temp_pouch, pouch_len);
// 	ft_memcpy(pouch + pouch_len, buffer, char_read);
// 	pouch[pouch_len + char_read] = '\0';
// 	free(temp_pouch);
// }

void	ft_read_and_save(int fd, char *pouch)
{
	char	*buffer;
	size_t	char_read;

	while (!ft_find_newline(pouch) && char_read)
	{
		buffer = (char *) malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		char_read = read(fd, buffer, BUFFER_SIZE);
		ft_add_to_pouch(pouch, buffer, char_read);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*pouch;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		while (pouch[i])
			pouch[i] = 0;
		return (NULL);
	line = NULL;
	if (!pouch)
		pouch = NULL;
	// pouch = NULL;
	line = ft_read_and_save(fd, pouch);
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
	printf("line: %s", get_next_line(fd));
	printf("line: %s", get_next_line(fd));
	close(fd);
	return (0);
}

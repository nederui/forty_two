/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 15:59:47 by egodinho          #+#    #+#             */
/*   Updated: 2022/11/28 21:26:31 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fun_get_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text[i])
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] == '\n')
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_save(char *text)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (!text[i])
	{
		free(text);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (strlen_gnl(text) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (text[i])
		str[j++] = text[i++];
	str[j] = '\0';
	free(text);
	return (str);
}

char	*read_and_join(int fd, char *text)
{
	char	*buff;
	int		read_ret;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_ret = 1;
	while (!strchr_gnl(text, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_ret] = '\0';
		text = strjoin_gnl(text, buff);
	}
	free(buff);
	buff = NULL;
	return (text);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*text;
	int			i;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
	{
		i = 0;
		while (text && text[i])
		{
			text[i] = 0;
			++i;
		}
		return (0);
	}
	text = read_and_join(fd, text);
	if (!text)
		return (NULL);
	line = fun_get_line(text);
	text = get_save(text);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*s;

// 	s = NULL;
// 	fd = open("ola.txt", O_RDONLY);
// 	if ((fd) == -1)
// 	{
// 		printf("file opening failed\n");
// 		exit(0);
// 	}
// 	else
// 	{
// 		s = get_next_line(fd);
// 		printf("%s", s);
// 		if (s)
// 			{
// 				free(s);
// 				s = NULL;
// 			}
// 		// s = get_next_line(fd);
// 		// printf("%s", s);
// 		// if (s)
// 		// 	free(s);
// 		// s = get_next_line(fd);
// 		// printf("%s", s);
// 		// if (s)
// 		// 	free(s);
// 		// s = get_next_line(fd);
// 		// printf("%s", s);
// 		// if (s)
// 		// 	free(s);
// 	}
// }

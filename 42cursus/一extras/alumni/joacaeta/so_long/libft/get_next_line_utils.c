/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:30:27 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:30:27 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	nl_index(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	lennl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	return (i + (str && str[i] == '\n'));
}

char	*get_line(char *line, char *buf)
{
	char	*dest;
	int		i;
	int		linesize;
	int		bufsize;

	linesize = lennl(line);
	bufsize = lennl(buf);
	dest = malloc(linesize + bufsize + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (line && i < linesize)
	{
		dest[i] = line[i];
		i++;
	}
	while (i - linesize < bufsize)
	{
		dest[i] = buf[i - linesize];
		i++;
	}
	if (line)
		free(line);
	dest[i] = '\0';
	return (dest);
}

void	clean_buf(char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = nl_index(buf);
	while (buf[i] != '\0')
	{
		if (i > k)
			buf[j++] = buf[i];
		buf[i++] = '\0';
	}
}

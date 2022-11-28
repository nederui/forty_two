/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 23:22:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 00:49:12 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	len_s1;

	len_s1 = ft_strlen((char *)s1);
	string = (char *) malloc(len_s1 + 1);
	if (string)
	{
		ft_memcpy(string, s1, len_s1);
		string[len_s1] = '\0';
	}
	return (string);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t buffer)
{
	char	*substr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (buffer > s_len - start)
		buffer = s_len - start;
	substr = (char *) malloc(buffer + 1);
	if (substr)
	{
		ft_memmove(substr, s + start, buffer);
		substr[buffer] = '\0';
	}
	return (substr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t buffer)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	if (buffer <= len_dst)
		return (buffer + ft_strlen((char *)src));
	while (src[i] && i < (buffer - len_dst - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen((char *)src));
}

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*string;
	size_t		i;
	size_t		i_s2;

	if (!s1 || !s2)
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
	return (string);
}

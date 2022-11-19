/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:39:50 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:39:50 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nb_words(char const *str, char c)
{
	size_t		i;
	size_t		nb;

	if (str)
	{
		i = 0;
		nb = 0;
		while (str[i] != '\0')
		{
			while (str[i] != '\0' && str[i] == c)
			{
				i++;
			}
			if (str[i] == '\0')
				return (0);
			while (str[i] != '\0' && str[i] != c)
				i++;
			nb++;
			while (str[i] != '\0' && str[i] == c)
				i++;
		}
		return (nb);
	}
	return (0);
}

unsigned int	strlcopy(char *dest, char const *src, unsigned int size)
{
	unsigned int	i;
	int				c;

	i = 0;
	c = 0;
	while ((src[c] != '\0'))
	{
		c++;
	}
	if (size != 0)
	{
		while ((i < (size - 1)) && (src[i] != '\0'))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (c);
}

int	strleng(char const *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	**alloc_word(char const *s, char c, char **r, size_t s_len)
{
	size_t	i;
	size_t	j;
	size_t	wrdsize;

	i = 0;
	j = 0;
	wrdsize = 0;
	while (i < s_len + 1 && s_len > 0)
	{
		if (s[i] == c || !s[i])
		{
			if (wrdsize > 0)
			{
				r[j] = (char *)malloc(wrdsize + 1);
				if (r[j])
					strlcopy(r[j], &s[i - wrdsize], wrdsize + 1);
				wrdsize = 0;
				j++;
			}
		}
		else
			wrdsize++;
		i++;
	}
	return (r);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	s_len;
	char	**r;

	if (!s)
		return (NULL);
	s_len = strleng(s);
	if (!s)
		return (NULL);
	words = nb_words(s, c);
	r = (char **)malloc(sizeof(char *) * (nb_words(s, c) + 1));
	if (!r)
		return (NULL);
	r = alloc_word(s, c, r, s_len);
	r[words] = NULL;
	return (r);
}

// int main(void)
// {
//     char    **lst;
//     int     i;

//     lst = ft_split("What a wonderful day outside", ' ');
//     i = 0;
//     while (lst[i])
//     {
//         printf("%s\n", lst[i]);
//         i++;
//     }
// }

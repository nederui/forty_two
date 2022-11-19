/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:41:35 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:41:35 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	strleng(char const *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	rg(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	if (!s || start > strleng(s))
		return (0);
	while (s[start] && i < len)
	{
		start++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	x;
	size_t	range;
	char	*r;

	if (!s)
		return (0);
	range = rg((char *)s, start, len);
	r = malloc(range + 1);
	i = 0;
	x = start;
	if (start <= strleng(s))
	{
		if (!r)
			return (0);
		while (s[i] && i < range)
		{
			r[i] = s[x];
			i++;
			x++;
		}
	}
	r[i] = '\0';
	return (r);
}

// int main(void)
// {
//     printf("%s\n", ft_substr("Hello guys", 2, 12));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:24:32 by merlin            #+#    #+#             */
/*   Updated: 2022/11/22 14:31:13 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *hidden, size_t n)
{
	size_t	i;
	size_t	f;

	i = 0;
	if (hidden[0] == '\0' || hidden == NULL)
		return ((char *)src);
	while (src[i] != '\0')
	{
		f = 0;
		while ((src[i + f] == hidden[f]) && (i + f < n))
		{
			if (hidden[f + 1] == '\0')
				return ((char *)src + i);
			f++;
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char	string_master[] = "this is a string.\n";
	char	find_me[] = " ";
	printf("%s", ft_strnstr(string_master, find_me, 5));
}
*/
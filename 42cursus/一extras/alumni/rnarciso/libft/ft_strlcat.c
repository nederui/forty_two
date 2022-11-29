/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:15:58 by merlin            #+#    #+#             */
/*   Updated: 2022/11/22 17:33:01 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	l;
	size_t	lengh_d;
	size_t	lengh_s;

	i = 0;
	l = 0;
	while (dest[i] != '\0')
		i++;
	lengh_d = i;
	lengh_s = ft_strlen(src);
	if (n == 0 || n <= lengh_d)
	{
		return (lengh_s + n);
	}
	while ((src[l] != '\0') && (l < (n - lengh_d - 1)))
	{
		dest[i] = src[l];
		i++;
		l++;
	}
	dest[i] = '\0';
	return (lengh_d + lengh_s);
}
/*
#include <stdio.h>

int	main(void)
{
	char	a[] = "Hello ";
	char	b[] = "World!";
	printf("%li\n", ft_strlcat(a, b, 11));
}
*/
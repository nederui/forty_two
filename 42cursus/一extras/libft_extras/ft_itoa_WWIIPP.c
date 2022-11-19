/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:41:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/14 21:02:55 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!src && !dst)
// 		return (NULL);
// 	while (i < n)
// 	{
// 		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 		i++;
// 	}
// 	return (dst);
// }

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char		*string;
// 	size_t		i;
// 	size_t		i_s2;

// 	if (!s1 || !s2)
// 		return (NULL);
// 	string = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 	if (string)
// 	{
// 		i = 0;
// 		i_s2 = i;
// 		while (i < ft_strlen(s1))
// 		{
// 			string[i] = s1[i];
// 			i++;
// 		}
// 		while (i_s2 < ft_strlen(s2))
// 		{
// 			string[i + i_s2] = s2[i_s2];
// 			i_s2++;
// 		}
// 		string[i + i_s2] = '\0';
// 	}
// 	return (string);
// }

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

// static char	*ft_free_willie(char *string)
// {
// 	free(string);
// 	return (string);
// }

static char	*ft_itoa_main(int n)
{
	char	*string;

	string = (char *) malloc(sizeof(char) * 2);
	if (string)
	{	
		if (n < 0)
		{
			free(string);
			if (n == -2147483648)
				return (ft_strdup("-2147483648"));
			string = (ft_strjoin(string, ft_itoa(-n)));
		}
		if (n > 9)
		{
			free(string);
			string = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
		}
		else if (n >= 0 && n < 10)
		{
			string[0] = n + 48;
			string[1] = '\0';
		}
	}
	return (string);
}

char	*ft_itoa(int n)
{
	char	*string;

	if (n >= 0)
		return (ft_itoa_main(n));
	else
	{
		string = ft_itoa_main(n);
		string[0] = '-';
		return (string);
	}
}

// Parameters		n: the integer to convert.

// Return value	The string representing the integer.
// 				NULL if the allocation fails.

// External functs. malloc

// Description		Allocates (with malloc(3)) and returns a string
// 				representing0 the integer received as an argument.
// 				Negative numbers must be handled.

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-21414140));
// 	return (0);
// }

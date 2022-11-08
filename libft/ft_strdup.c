/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:16:29 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/07 05:14:45 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// char *
// strndup(const char *s1, size_t n);

// DESCRIPTION
// The strdup() function allocates sufficient memory for a copy of
// the string s1, does the copy, and returns a pointer to it. 
// The pointer may subsequently be used as an argument to
// the function free(3).

// If insufficient memory is available,
// NULL is returned and errno is set to ENOMEM.

// The strndup() function copies at most n characters from the string s1
// always NUL terminating the copied string.

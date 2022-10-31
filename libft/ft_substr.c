/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:21:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/31 01:45:05 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	len_s;

	len_s = ft_strlen(s[start]);
	if (len_s > len)
		len_s = len;
	substr = (char *) malloc(len_s + 1);
	if (substr)
		ft_memcpy(substr, s[start], len);
	substr[len_s] = '\0';
	return (substr);
}

// PARAMETERS:
//                 s: The string from which to create the substring.
//                 start: The start index of the substring in thestring ’s’.
//                 len: The maximum length of the substring.

// Return value:   The substring.
//                 NULL if the allocation fails.

// Description:    Allocates (with malloc(3)) and returns a substring
//                 from the string ’s’.

//                 The substring begins at index ’start’ and is of
//                 maximum size ’len’.

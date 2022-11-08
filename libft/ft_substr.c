/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:21:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 04:23:19 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s || len == 0)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr = malloc(sizeof(char));
		if (substr)
			substr[0] = '\0';
		return (substr);
	}
	substr = (char *) malloc(len + 1);
	if (substr)
	{
		ft_memcpy(substr, s + start, len);
		substr[len] = '\0';
	}
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

// int		main(void)
// {
// 	char	str[] = "lorem ipsum dolor sit amet";

// 	char	*sub = ft_substr(str, 22, 8);

// 	for (int i = 0; i < 8; i++)
// 		printf("sub[%d]: %s\n", i, &sub[i]); 	
// 	// printf("%s", ft_substr(str, 22, 8));
// }

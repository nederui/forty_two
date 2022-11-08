/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:51:32 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:41:01 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_index;
	unsigned int	src_index;
	unsigned int	returnval;

	dest_index = 0;
	src_index = 0;
	returnval = 0;
	while (dest[dest_index])
		dest_index++;
	while (src[returnval])
		returnval++;
	if (size <= dest_index)
		returnval += size;
	else
		returnval += dest_index;
	while (src[src_index] && (dest_index + 1) < size)
	{
		dest[dest_index] = src[src_index];
		dest_index++;
		src_index++;
	}
	dest[dest_index] = '\0';
	return (returnval);
}

// int	main(void)
// {
// 	char	st1[1024] = "Hello ";
// 	char	st2[] = "World";
// 	int		n = 6;
// 	printf("%d\n", ft_strlcat(st1, st2, n));
// 	// printf("%lu\n", strlcat(st1,st2,n));
// 	printf("%s", st1);
// }

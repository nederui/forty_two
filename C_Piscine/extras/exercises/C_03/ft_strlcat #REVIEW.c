/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:15:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/17 08:15:44 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_i;
	unsigned int	dest_i;

	src_i = 0;
	dest_i = 0;
	while (dest[dest_i] != '\0')
		dest_i++;
	// while (src[src_i] != '\0')
	// 	src_i++;
	// if (dest_i >= size)
	// 	return (size);
	// else
	// 	return (dest_i + 1);
	while (src[src_i] != '\0' && (dest_i + 1) < size)
	{
		dest[dest_i + src_i] = src[src_i];
		src_i++;
	}	
	dest[dest_i + src_i] = '\0';
	return (dest_i);
}

// unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
// {
// 	unsigned int	i_src;
// 	unsigned int	i_dest;

// 	i_src = 0;
// 	i_dest = 0;
// 	if (size > 0)
// 	{
// 		while (dest[i_dest] != '\0')
// 			i_dest++;
// 		while (src[i_src] != '\0' && i_src < size)
// 		{
// 			dest[i_dest + i_src] = src[i_src];
// 			i_src++;
// 		}
// 		dest[i_dest + i_src] = '\0';
// 		return (i_dest);
// 	}
// 	return (i_dest);
// }

void			ft_strlcat_test(char *dest, char *ft_dest, char *src, unsigned int size)
{
	unsigned int	return_value;
	unsigned int	ft_return_value;

	return_value = strlcat(dest, src, size);
	ft_return_value = ft_strlcat(ft_dest, src, size);
	if (return_value != ft_return_value)
		printf("> KO, expected: %u, got: %u\n", return_value, ft_return_value);
	else if (strcmp(dest, ft_dest) != 0)
		printf("> KO, expected: %s, got: %s\n", dest, ft_dest);
	else
		printf("> OK, result: %s\n", ft_dest);
}

int				main(void)
{
	char			*src;
	char			*dest;
	char			*ft_dest;

	// invalid case, dest is non null terminated in the first size - 1 bytes.
	src = "stuv";
	dest = "abcdefghijklmnopr";
	ft_dest = "abcdefghijklmnopr";
	ft_strlcat_test(dest, ft_dest, src, 0);
	ft_strlcat_test(dest, ft_dest, src, 1);
	ft_strlcat_test(dest, ft_dest, src, 4);
	ft_strlcat_test(dest, ft_dest, src, 10);
	// valid case, dest is null terminated in the first size - 1 bytes, modified and terminated
	src = "ghijkl";
	dest = strcpy(calloc(13, sizeof(char)), "abcdef");
	ft_dest = strcpy(calloc(13, sizeof(char)), "abcdef");
	ft_strlcat_test(dest, ft_dest, src, 8);
	ft_strlcat_test(dest, ft_dest, src, 10);
	return (0);
}
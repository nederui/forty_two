/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:19:39 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/10 04:37:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i_2;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		i_2 = 0;
		while (haystack[i + i_2] == needle[i_2] && (i + i_2) < len)
		{
			if (!needle[i_2 + 1])
				return ((char *)haystack + i);
			i_2++;
		}
		i++;
	}
	return (NULL);
}

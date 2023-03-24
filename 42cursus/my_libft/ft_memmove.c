/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:12:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/24 17:28:42 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*
• if we're unsure whether or not the 'dst' & 'src' blocks of memory
• will overlap, then we should use ft_memmove() instead of ft_memcpy() because
• it's guaranteed to be safe.
*/

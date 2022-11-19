/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:16:18 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:17 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (!size)
		return (0);
	i = ft_strlen(dst);
	if (i > size)
		return (ft_strlen(src) + size);
	len = ft_strlen(src) + i;
	j = 0;
	if (*src && size)
	{
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (len);
}

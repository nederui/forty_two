/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:01:19 by amak              #+#    #+#             */
/*   Updated: 2022/10/30 01:01:08 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t bsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	pos;

	dst_length = (size_t)ft_strlen(dst);
	src_length = (size_t)ft_strlen((char *)src);
	pos = 0;
	if (bsize == 0 || bsize <= dst_length)
		return (bsize + src_length);
	while ((src[pos] != '\0') && (pos < (bsize - dst_length - 1)))
	{
			dst[dst_length + pos] = src[pos];
			pos++;
	}
	dst[dst_length + pos] = '\0';
	return (dst_length + src_length);
}

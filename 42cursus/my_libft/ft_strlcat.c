/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:18:01 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/24 17:27:58 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t buffer)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	if (buffer <= len_dst)
		return (buffer + ft_strlen((char *)src));
	while (src[i] && i < (buffer - len_dst - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen((char *)src));
}

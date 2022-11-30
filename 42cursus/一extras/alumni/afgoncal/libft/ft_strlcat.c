/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afgoncal <massenaafonso1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:35:13 by afgoncal          #+#    #+#             */
/*   Updated: 2022/11/07 16:02:51 by afgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, char *src, size_t n)
{
	size_t	d_size;
	size_t	s_size;
	size_t	i;

	i = 0;
	s_size = ft_strlen(src);
	d_size = ft_strlen(dst);
	if (n == 0 || n <= d_size)
		return (s_size + n);
	while (src[i] && i < n - d_size - 1)
	{
		dst[d_size + i] = src[i];
		i++;
	}
	dst[d_size + i] = '\0';
	return (d_size + s_size);
}

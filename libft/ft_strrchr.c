/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:19:58 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/30 14:20:08 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	
	i = ft_strlen((char *)s) - 1;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((char *)s+i);
		i--;
	}
	return (0);
}

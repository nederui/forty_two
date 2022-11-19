/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:36:48 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:36:48 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*r;

	if (size > 0)
	{
		r = malloc(nmemb * size);
		if (!r)
			return (0);
		ft_memset(r, 0, nmemb * size);
	}
	else
	{
		r = malloc(0);
		if (!r)
			return (0);
	}
	return ((void *)r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:12:09 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:04 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*addr;

	addr = malloc(nmemb * size);
	if (!addr)
		return (NULL);
	ft_bzero(addr, nmemb * size);
	if (!addr)
		return (NULL);
	return (addr);
}

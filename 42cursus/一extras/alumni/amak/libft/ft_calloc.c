/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:30:33 by amak              #+#    #+#             */
/*   Updated: 2022/11/20 02:58:32 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*pnt;
	size_t	pos;

	pos = 0;
	pnt = (char *)malloc(nmemb * size);
	if (pnt == NULL)
		return (NULL);
	while (pos < (nmemb * size))
	{
		pnt[pos] = '\0';
		pos++;
	}
	return ((void *)pnt);
}

//	“calloc” or “contiguous allocation” method in C is used to dynamically
//	allocate the specified number of blocks of memory of the specified type. 
//	It is very much similar to malloc() but has two different points and 
// 	these are:
//  - It initializes each block with a default value ‘0’.
//  - It has two parameters or arguments as compare to malloc().
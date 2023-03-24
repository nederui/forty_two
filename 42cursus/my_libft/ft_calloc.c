/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:06:54 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/24 17:29:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;

	array = (char *) malloc(nmemb * size);
	if (array)
		ft_bzero(array, nmemb * size);
	return (array);
}

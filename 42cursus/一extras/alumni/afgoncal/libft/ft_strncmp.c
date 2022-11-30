/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afgoncal <massenaafonso1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:10:15 by afgoncal          #+#    #+#             */
/*   Updated: 2022/11/04 12:21:57 by afgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((char)s1[i] == (char)s2[i] && ((char)s1[i] != '\0'
			|| (char)s2[i] != '\0' ) && (i < n - 1))
	{
		i++;
	}	
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

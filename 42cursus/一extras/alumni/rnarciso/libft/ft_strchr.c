/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 05:00:03 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/22 07:59:08 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)str + i);
	return (0);
}
/*
#include <stdio.h>

int main (void) 
{
   const char str[] = "This is just a String"; 
   const char ch = 'T'; 
   char *p;
   p = ft_strchr(str, ch);
   printf("String starting from %c is: %s\n", ch, p);
   return 0;
}
*/
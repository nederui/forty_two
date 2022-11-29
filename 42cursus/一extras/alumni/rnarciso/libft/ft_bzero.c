/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 07:56:45 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/18 09:09:28 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{	
		temp[i] = '\0';
		i++;
	}
}
/*
#include <string.h>

int main( void )
  {
    char buffer[80];

    bzero( buffer, 80 );
    return EXIT_SUCCESS;
  }
*/
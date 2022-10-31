/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:13:14 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/31 01:57:17 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
• the original memset() writes 'n' bytes of value 'c' (converted to an
• unsigned char) to the destination string 'b';
•
• it returns its first argument (string 'b');
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

/*
• we use CASTING to avoid getting the error "Incomplete type 'void' is
• not assignable";
•
• if we want to write data in string 'b', first we need to tell the computer
• how large is the data we're trying to write;
•
• we want to write an 'n' number of bytes in string 'b' - and we know that
• a char takes 1 byte of space;
•
• so we CAST string 'b' to char, and have a loop copying 'c', 'n' times to 'b'
*/

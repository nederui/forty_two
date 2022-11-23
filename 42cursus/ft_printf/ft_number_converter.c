/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:44:29 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/23 00:40:31 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
the aim of this function is to be as universal as possible, handling most of
the conversions needed for each format to be written by ft_printf()
*/

#include "ft_printf.h"

int	ft_number_converter(long number, char *base, long size)
{
	int	bytes;

	bytes = 0;
	if (number < 0)
	{
		number = -number;
		bytes = bytes + write(1, "-", 1);
	}
	if (number >= size)
		bytes = bytes + ft_number_converter(number / size, base, size);
	bytes = bytes + write(1, &base[number % size], 1);
	return (bytes);
}

/* 
we use the 'long' data type to include the number range of four different
formats, and we increment 'bytes' for each character outputted by write()

'&base[number % size]' tells write() to print the character corresponding to
the position matching the current result of 'number % size' of the base,
passed as a parameter 'char *'
*/

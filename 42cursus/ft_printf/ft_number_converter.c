/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:44:29 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/23 13:32:28 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/* 
the aim of this function is to be as universal as possible, handling most of
the conversions needed for each format to be written by ft_printf()

we use the 'long' data type to include the number range of four different
formats, and we increment 'total_bytes' for each character outputted by write()

'&base[number % base]' tells write() to print the character corresponding to
the position matching the current result of 'number % base' of the base,
passed as a parameter 'char *'
*/

int	ft_number_converter(long number, char *base_string, long base)
{
	int	total_bytes;

	total_bytes = 0;
	if (number < 0)
	{
		number = -number;
		total_bytes += write(1, "-", 1);
	}
	if (number >= base)
		total_bytes += ft_number_converter(number / base, base_string, base);
	total_bytes += write(1, base_string + (number % base), 1);
	return (total_bytes);
}

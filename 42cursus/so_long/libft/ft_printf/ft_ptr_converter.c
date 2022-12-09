/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:34:23 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:32:55 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

/*
'uintptr_t' data type to make sure that:
we include the full range of a possible pointer's address & that the 
converted hexadecimal is positive (as memory addresses are always positive)

'&"0123456789abcdef"[number % 16' tells write() to print the char
corresponding to the position matching the current result of 'number % 16'
of the string "0123456789abcdef"
*/

int	ft_ptr_converter(uintptr_t number)
{
	int		total_bytes;

	total_bytes = 0;
	if (number >= 16)
		total_bytes += ft_ptr_converter(number / 16);
	total_bytes += write(1, &"0123456789abcdef"[number % 16], 1);
	return (total_bytes);
}

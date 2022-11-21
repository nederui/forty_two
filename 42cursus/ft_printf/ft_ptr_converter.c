/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:34:23 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 19:48:18 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_converter(unsigned long number)
{
	int		bytes;

	bytes = 0;
	if (number >= 16UL)
		bytes = bytes + ft_ptr_converter(number / 16UL);
	bytes = bytes + write(1, &HEX_LOW[number % 16UL], 1);
	return (bytes);
}

// 'unsigned long' data type to make sure that:
// we include the full range of a possible pointer's address & that the 
// converted hexadecimal is positive (as memory addresses are always positive)
//
// '16UL' is short for '(unsigned long)16' & 'HEX_LOW' (expands to the string
// "0123456789abcdef") is a macro pre-defined in 'ft_print.h';
// both cases were implentmented with the purpose of making the lines shorter
//
// '&HEX_LOW[number % 16UL]' tells write() to print the char corresponding to
// the position matching the current result of 'number % 16UL' of the string
// "0123456789abcdef"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:47:12 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/23 13:38:39 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <unistd.h>

/* 
each call of 'va_arg()' returns one argument and steps *agrs to the next

'DEC', 'HEX_LOW', 'HEX_UP' are macros pre-defined in 'ft_print.h',
all implentmented with the purpose of making the lines shorter

'write(1, "0x", 2)' matches the prefix '0x' that printf() adds to %p format
in the special case of a null-pointer (number == 0), the original printf()
prints '(nil)' - (as the memory at address 0 will never be allocated) 
*/

int	ft_format_identifier(char c, va_list *args)
{
	uintptr_t	number;

	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 'd' || c == 'i')
		return (ft_number_converter(va_arg(*args, int), DEC, 10));
	if (c == 'p')
	{
		number = va_arg(*args, uintptr_t);
		if (number == 0)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_ptr_converter(number));
	}
	if (c == 's' || c == 'c')
		return (ft_putstr(va_arg(*args, char *)));
	if (c == 'u')
		return (ft_number_converter(va_arg(*args, unsigned int), DEC, 10));
	if (c == 'x')
		return (ft_number_converter(va_arg(*args, unsigned int), HEX_LOW, 16));
	if (c == 'X')
		return (ft_number_converter(va_arg(*args, unsigned int), HEX_UP, 16));
	return (0);
}

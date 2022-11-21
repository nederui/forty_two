/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:47:12 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 02:26:53 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_identifier(char c, va_list *args)
{
	unsigned long	number;

	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar_int (va_arg(*args, int)));
	if (c == 'd' || c == 'i')
		return (ft_number_converter(va_arg(*args, int), DEC, 10));
	if (c == 'p')
	{
		number = va_arg(*args, unsigned long);
		if (number == 0)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_ptr_converter(number));
	}
	if (c == 's')
		return (ft_putstr_int (va_arg(*args, char *)));
	if (c == 'u')
		return (ft_number_converter(va_arg(*args, unsigned int), DEC, 10));
	if (c == 'x')
		return (ft_number_converter(va_arg(*args, unsigned int), HEX_LOW, 16));
	if (c == 'X')
		return (ft_number_converter(va_arg(*args, unsigned int), HEX_UP, 16));
	return (0);
}

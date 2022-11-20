/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_identifier.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:47:12 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 20:48:17 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	ft_format_identifier(char c, va_list *args)
{
	t_ul	n;

	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar_int (va_arg(*args, int)));
	if (c == 'd' || c == 'i')
		return (ft_number_converter(va_arg(*args, int), DEC, 10));
	if (c == 'p')
	{
		n = va_arg(*args, t_ul);
		if (n == 0)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_number_converter(n, HEX_LOW, 16));
	}
	if (c == 's')
		return (ft_putstr_int (va_arg(*args, char *)));
	if (c == 'u')
		ft_number_converter(va_arg(*args, unsigned int), DEC, 10);
	if (c == 'x')
		return (ft_number_converter(va_arg(*args, unsigned int), HEX_LOW, 16));
	if (c == 'X')
		return (ft_number_converter(va_arg(*args, unsigned int), HEX_UP, 16));
	return (0);
}

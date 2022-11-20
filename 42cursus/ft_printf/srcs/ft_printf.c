/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 20:05:44 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftprintf.h"
// #include <stdio.h>

int	ft_converter(double number, char *base, double size)
{
	int	bytes;

	bytes = 0;
	if (number < 0)
	{
		number = -number;
		bytes = bytes + write(1, "-", 1);
	}
	if (number >= size)
		bytes = bytes + ft_converter(number / size, base, size);
	bytes = bytes + write(1, &base[(t_ul)number % (t_ul)size], 1);
	return (bytes);
}

int	ft_format_identifier(char c, va_list *args)
{
	t_ul	n;

	if (c == '%')
		return (write(1, "%", 1));
	if (c == 'c')
		return (ft_putchar_int (va_arg(*args, int)));
	if (c == 'd' || c == 'i')
		return (ft_converter(va_arg(*args, int), "0123456789", 10));
	if (c == 'p')
	{
		n = va_arg(*args, t_ul);
		if (n == 0)
			return (write(1, "(nil)", 5));
		return (write(1, "0x", 2) + ft_converter(n, HEX, 16));
	}
	if (c == 's')
		return (ft_putstr_int (va_arg(*args, char *)));
	if (c == 'u')
		ft_converter(va_arg(*args, unsigned int), "0123456789", 10);
	if (c == 'x' || c == 'X')
	{
		return (ft_converter(va_arg(*args, unsigned int), HEX, 16));
		return (ft_converter(va_arg(*args, unsigned int), HEX, 1));
	}
	return (0);
}

int	ft_printf(const char *format_string, ...)
{
	va_list	arguments;
	int		bytes;
	int		i;

	i = 0;
	bytes = 0;
	va_start(arguments, format_string);
	while (format_string[i])
	{
		if (format_string[i] == '%')
		{
			i++;
			bytes = bytes + ft_format_identifier(format_string[i], &arguments);
		}
		else
			bytes = bytes + write(1, &format_string[i], 1);
		i++;
	}
	va_end(arguments);
	return (bytes);
}

// int	main(void)
// {
// 	int		a = 2130;
// 	char	x = 'A';
// 	char	*s = "42_school";
// 	unsigned int	u = 2222222222;
// 	int	k = 35515000;

// 	ft_printf("%%\n%i\n%c\n%u\n%x\n%X\n%p\n%s", a, x, u, k, k, s, s);
// 	ft_printf("\n\n");
// 	printf("%%\n%i\n%c\n%u\n%x\n%X\n%p\n%s", a, x, u, k, k, s, s);
// 	ft_printf("\n");
// 	return (0);
// }

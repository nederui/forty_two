/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/18 18:53:02 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftprintf.h"
#include <stdio.h>

// ft_putaddr();

int	ft_converter(double number, char *base, double size)
{
	int	bytes;

	bytes = 0;
	if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
	}
	if (number >= size)
		bytes = bytes + converter ((number / size), base, size);
	bytes = bytes + write (1, &base[(unsigned long)number % (unsigned long)size], 1);
	return (bytes);
}

int	ft_format_identifier(char c, va_list *arguments)
{
	if (c == '%')
		write(1, "%", 1);
	if (c == 'c')
		ft_putchar_fd (va_arg(*arguments, int), 1);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(*arguments, int), 1);
	// if (c == 'p')
	// 	ft_putaddr(va_arg(*arguments, );
	if (c == 's')
		ft_putstr_fd (va_arg(*arguments, char *), 1);
	if (c == 'u')
		ft_converter(va_arg(*arguments, unsigned int), "0123456789", 10);
	if (c == 'x' || c == 'X')
	{
		ft_converter(va_arg(*arguments, unsigned int), "0123456789abcdef", 16);
		ft_converter(va_arg(*arguments, unsigned int), "0123456789ABCDEF", 16);
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

int	main(void)
{
	int		a = 55;
	char	x = 'x';
	char	*s = "42_school";
	unsigned int	u = 2222222222; 
	// %u NEEDS TO BE UNSIGNED DECIMAL base 10
	// %p The void * pointer argument has to be printed in hexadecimal format.
	// %x Prints a number in hexadecimal (base 16) lowercase format.
	// // %X Prints a number in hexadecimal (base 16) uppercase format.
	ft_printf("string: %s\n%%: %%\nunsigned decimal: %u\nint: %i\nchar: %c\n", s, u, a, x);
	
	ft_printf("\nreturn values:\nprintf: %d\nft_printf: %d", printf("\n (%d)", a), ft_printf("\n (%d)", a));
	return (0);
}

// You have to implement the following conversions:
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.
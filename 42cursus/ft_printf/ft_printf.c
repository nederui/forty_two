/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 20:50:05 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"
#include <stdio.h>

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
	int		a = 2130;
	char	x = 'A';
	char	*s = "42_school";
	unsigned int	u = 2222222222;
	int	k = 35515000;
	// ft_printf("string: %s\n%%: %%\nunsigned decimal: %u\nint: %i\nchar: %c\n", s, u, a, x);
	// ft_putnbr_fd(ft_printf("\n%p\n", s), 1);
	// printf("\n");
	// ft_putnbr_fd(printf("\n%p\n", s), 1);
	// ft_printf("\nreturn values:\nprintf: %d\nft_printf: %d", printf("\n (%d)", a), ft_printf("\n (%d)", a));

	ft_printf("%%\n%i\n%c\n%u\n%x\n%X\n%p\n%s", a, x, u, k, k, s, s);
	ft_printf("\n\n");
	printf("%%\n%i\n%c\n%u\n%x\n%X\n%p\n%s", a, x, u, k, k, s, s);
	ft_printf("\n");
	return (0);
}

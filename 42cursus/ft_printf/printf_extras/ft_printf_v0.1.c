/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/17 19:03:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftprintf.h"

int	ft_printf(const char *string, ...)
{
	va_list				arguments;
	size_t				i;
	int					x;
	int					chr;
	unsigned int		y;
	char				*z;

	i = 0;
	va_start(arguments, string);
	while (i < ft_strlen(string))
	{
		if (((char *)string)[i] == '%')
		{
			i++;
			if (((char *)string)[i] == 'i')
			{
				x = va_arg(arguments, int);
				ft_putnbr_fd(x, 1);
			}
			else if (((char *)string)[i] == 'u')
			{
				y = va_arg(arguments, unsigned int);
				ft_putstr_fd(ft_unitoa(y), 1);
			}
			else if (((char *)string)[i] == 'c')
			{
				chr = va_arg(arguments, int);
				write(1, &chr, 1);
			}
			else if (((char *)string)[i] == 's')
			{
				z = va_arg(arguments, char *);
				ft_putstr_fd(z, 1);
			}
			else if (((char *)string)[i] == '%')
				write(1, "%", 1);
		}
		else
			write(1, &((char *)string)[i], 1);
		i++;
	}
	va_end(arguments);
	return (ft_strlen(string));
}

int	main(void)
{
	int		a = 5;
	char	x = 'x';
	char	*s = "42_school";
	unsigned int	u = 2222222222; 
	// %u NEEDS TO BE UNSIGNED DECIMAL base 10
	// %p The void * pointer argument has to be printed in hexadecimal format.
	// %x Prints a number in hexadecimal (base 16) lowercase format.
	// %X Prints a number in hexadecimal (base 16) uppercase format.
	ft_printf("string: %s\n%%: %%\nunsigned decimal: %u\nint: %i\nchar: %c\n", s, u, a, x);

	return (0);
}

// You have to implement the following conversions:
// • %p The void * pointer argument has to be printed in hexadecimal format.
// • %d Prints a decimal (base 10) number.
// • %u Prints an unsigned decimal (base 10) number.
// • %x Prints a number in hexadecimal (base 16) lowercase format.
// • %X Prints a number in hexadecimal (base 16) uppercase format.
// • %% Prints a percent sign.
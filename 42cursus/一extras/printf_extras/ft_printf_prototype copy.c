/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/16 18:32:09 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	ft_printf(const char *string, ...)
{
	va_list	arguments;
	size_t	i;
	size_t	string_len;
	int		x;
	int		y;
	int		num_arg;
	char	*z;

	i = 0;
	string_len = ft_strlen(string);
	va_start(arguments, string);
	while (i < string_len)
	{
		if (((char *)string)[i] == '%' && ((char *)string)[i + 1] == 'd')
		{
			x = va_arg(arguments, int);
			ft_putnbr_fd(x, 1);
			num_arg++;
		}
		else if (((char *)string)[i] == '%' && ((char *)string)[i + 1] == 'c')
		{
			y = va_arg(arguments, int);
			write(1, &y, 1);
			num_arg++;
		}
		else if (((char *)string)[i] == '%' && ((char *)string)[i + 1] == '%')
		{
			write(1, "%", 1);
		}
		else if (((char *)string)[i] == '%' && ((char *)string)[i + 1] == 's')
		{
			z = va_arg(arguments, char *);
			ft_putstr_fd(z, 1);
			num_arg++;
		}
		else if (((char *)string)[i] == '\n')
			write(1, "\n", 1);
		i++;
	}
	write(1, "\n", 1);
	write(1, "string lenght: ", 15);
	ft_putnbr_fd((int)string_len, 1);
	write(1, "\n", 1);
	write(1, "number of arguments: ", 21);
	ft_putnbr_fd(num_arg, 1);
	write(1, "\n", 1);
	va_end(arguments);
	return (0);
}




// #include <stdio.h>
// int printf(const char *format-string, argument-list);


int	main(void)
{
	int		a = 5, b = 9, c = 3001, d = 2;
	char	x = 'x', y = 'y', z = 'z';
	char	*s = "42_school";
	ft_printf("%s\n%%\n%d\n%d\n%d\n%d\n%c%c%c", s, a, b, c, d, x, y, z);

	return (0);
}

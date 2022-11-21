/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 20:12:29 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

// 'va_start' initializes the ap (argument pointer) 'arguments' to the first
// unnamed argument. it must be called once before 'arguments' is used
//
// 'va_end' does whatever cleanup is necessary. must be called before RETURN
//
// the RETURN value (bytes) increments for each character outputted

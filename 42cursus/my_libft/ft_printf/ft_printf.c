/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/24 17:21:04 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

/* 
'va_start' initializes the ap (argument pointer) 'arguments' to the first
unnamed argument. it must be called once before 'arguments' is used

'va_end' does whatever cleanup is necessary. must be called before RETURN

the RETURN value (total_bytes) increments for each character outputted
*/

int	ft_printf(const char *format_string, ...)
{
	va_list	arguments;
	int		total_bytes;
	int		i;

	i = 0;
	total_bytes = 0;
	va_start(arguments, format_string);
	while (format_string[i])
	{
		if (format_string[i] == '%')
		{
			++i;
			total_bytes += ft_format_identifier(format_string[i], &arguments);
		}
		else
			total_bytes += write(1, format_string + i, 1);
		++i;
	}
	va_end(arguments);
	return (total_bytes);
}

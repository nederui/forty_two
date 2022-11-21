/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 02:39:16 by nfilipe-         ###   ########.fr       */
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

//
// %p in printf formats a pointer type. This is going to distinguish
// a null-pointer and print (nil) because it is a special value in the 
// context of a pointer.
//
// NULL is a macro defined as 0 or ((void *) 0), so if you set 
// a pointer to NULL it's exactly the same as setting it to 0. 
// This works for the purposed of declaring null pointers because 
// the memory at address 0 will never be allocated to your program.
//

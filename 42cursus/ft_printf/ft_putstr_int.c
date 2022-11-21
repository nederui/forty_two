/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:35:34 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 20:13:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this function is a modified version of the original ft_putstr(), to match
// ft_printf()'s RETURN value -  the number of bytes written, as well as,
// outputting "(null)" in the special case of printing a null-pointer string; 

#include "ft_printf.h"

int	ft_putstr_int(char *s)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		bytes = bytes + write(1, &s[i], 1);
		i++;
	}
	return (bytes);
}

// the RETURN value (bytes) increments for each character outputted by write()

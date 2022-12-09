/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:35:34 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/07 19:28:12 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

/* 
this function is a modified version of the original ft_putstr(), to match
ft_printf()'s RETURN value - the number of total_bytes written, as well as,
outputting "(null)" in the special case of printing a null-pointer string; 
*/

int	ft_putstr_pf(char *s)
{
	int	i;
	int	total_bytes;

	i = 0;
	total_bytes = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		total_bytes += write(1, &s[i], 1);
		++i;
	}
	return (total_bytes);
}

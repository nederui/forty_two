/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_converter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:44:29 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 01:51:39 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_number_converter(long number, char *base, long size)
{
	int	bytes;

	bytes = 0;
	if (number < 0)
	{
		number = -number;
		bytes = bytes + write(1, "-", 1);
	}
	if (number >= size)
		bytes = bytes + ft_number_converter(number / size, base, size);
	bytes = bytes + write(1, &base[number % size], 1);
	return (bytes);
}

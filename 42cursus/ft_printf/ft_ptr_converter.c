/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_converter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 01:34:23 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 02:34:02 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_converter(unsigned long number)
{
	int		bytes;

	bytes = 0;
	if (number >= 16UL)
		bytes = bytes + ft_ptr_converter(number / 16UL);
	bytes = bytes + write(1, &HEX_LOW[number % 16UL], 1);
	return (bytes);
}

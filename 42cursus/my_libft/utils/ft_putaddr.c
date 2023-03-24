/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:39:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:33:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

static void	ft_ptr_converter(uintptr_t number, char *base)
{
	if (number >= 16)
		ft_ptr_converter(number / 16, base);
	write(1, &base[number % 16], 1);
}

void	ft_putaddr(void *ptr)
{
	char	*base_string;

	if (ptr == 0)
		write(1, "(nil)", 5);
	else
	{
		base_string = "0123456789abcdef";
		write(1, "0x", 2);
		ft_ptr_converter((uintptr_t)ptr, base_string);
	}
}

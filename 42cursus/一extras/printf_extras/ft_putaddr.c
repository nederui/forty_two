/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:39:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 22:30:31 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_ptr_converter(unsigned long number, char *base)
{
	if (number >= 16)
		ft_ptr_converter(number / 16, base);
	write(1, &base[number % 16], 1);
}

void	ft_putaddr(char *ptr)
{
	if (ptr == 0)
		write(1, "(nil)", 5);
	else
	{
		write(1, "0x", 2);
		ft_ptr_converter((unsigned long)ptr, "0123456789abcdef");
	}
}

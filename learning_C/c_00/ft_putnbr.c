/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:15:58 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/13 19:25:31 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		printer('-');
		printer('2');
		ft_putnbr(147483648);
	}
	if (nb < 0 && nb != -2147483648)
	{
		printer('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		if (nb != -2147483648)
		{
			printer(nb + 48);
		}
	}
}
// recursive function - stacks
// nb = -nb
// -2147483648
// /10 %10
// 
// negative numbers {-}
	// zero (?)
	// positive numbers {}
	// 	-2,147,483,648 to +2,147,483,647
	
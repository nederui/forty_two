/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:15:58 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/12 17:34:29 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr_fd(int nb)
{
	if (nb == -2147483648)
	{
		printer('-');
		printer('2');
		ft_putnbr_fd(147483648);
	}
	if (nb < 0 && nb != -2147483648)
	{
		printer('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10);
		ft_putnbr_fd(nb % 10);
	}
	else
	{
		if (nb != -2147483648)
		{
			printer(nb + 48);
		}
	}
}

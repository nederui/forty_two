/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 17:31:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/10 20:37:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != 55)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(int a, int b, int c)
{
	a = 48;
	b = 49;
	c = 50;
	while (c < 58)
	{
		printer(a, b, c);
		c++;
		if (c == 58)
		{
			c = 0;
			b++;
			if (b == 57)
			{
				b = 0;
				a++;
				while (b <= a)
					b++;
			}
			while (c <= b)
				c++;
		}
	}
}

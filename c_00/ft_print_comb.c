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

void	printnumb(int a, int b, int c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a != 55)
	{
		write(1, ", ", 2);
	}
}

void	incremental(int a, int b, int c)
{
	while (c < 58)
	{
		printnumb(a, b, c);
		c++;
		if (c == 58)
		{
			c = b;
			b++;
			if (b == 57)
			{
				b = a;
				a++;
				while (b <= a)
				{
					b++;
				}
			}
			while (c <= b)
			{
				c++;
			}	
		}
	}
}

void	ft_print_comb(void)
{
	incremental(48, 49, 50);
}

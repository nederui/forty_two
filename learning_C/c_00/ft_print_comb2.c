/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 21:11:31 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/11 18:56:34 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printnumb(int numb)
{
	write(1, &numb, 1);
}

void	ft_print_comb2(int aa, int bb)
{
	aa = 0;
	bb = aa +1;
	while (aa < 99)
	{
		printnumb (aa / 10 + '0');
		printnumb (aa % 10 + '0');
		printnumb (' ');
		printnumb (bb / 10 + '0');
		printnumb (bb % 10 + '0');
		if (aa != 98)
		{
			write(1, ", ", 2);
		}
		bb++;
		if (bb == 100)
		{
			bb = aa;
			aa++;
			while (bb <= aa)
			{
				bb++;
			}
		}
	}
}

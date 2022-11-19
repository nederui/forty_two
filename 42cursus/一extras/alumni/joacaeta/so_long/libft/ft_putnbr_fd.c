/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:39:34 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:39:35 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

char	*allnb(int nb, char *alln, int fd)
{
	int		a;
	long	b;
	int		mod;

	b = (long)nb;
	a = 9;
	if (b != 0)
	{
		if (b < 0)
		{
			write(fd, "-", 1);
			b = -1 * b;
		}
		while (b > 0)
		{
			mod = (b % 10) + 48;
			alln[a] = mod;
			a--;
			b = b / 10;
		}
	}
	else
		alln[a] = 48;
	return (alln);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char	alln[10];
	int		i;
	int		a;

	a = 9;
	i = 0;
	while (a >= 0)
	{
		alln[a] = '\0';
		a--;
	}
	allnb(nb, alln, fd);
	while (i < 10)
	{
		if (alln[i] != '\0')
			write(fd, &alln[i], 1);
		i++;
	}
}

// int main(void)
// {
// 	int c = '\n';
// 	ft_putnbr(-2147483648);
// 	printf("%c",c);
// 	ft_putnbr(-23);
// 	printf("%c",c);
// 	ft_putnbr(-4);
// 	printf("%c",c);
// 	ft_putnbr(0);
// 	printf("%c",c);
// 	ft_putnbr(5);
// 	printf("%c",c);
// 	ft_putnbr(234);
// 	printf("%c",c);
// 	ft_putnbr(2111111111);
// 	printf("%c",c);
// 	ft_putnbr(2147483647);
// 	printf("%c",c);
// }

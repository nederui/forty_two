/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:59:00 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:05 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_fact(int nbr)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr / 10 != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	assign_nums(char *str, int nb)
{
	if (nb > 9)
		assign_nums(str - 1, nb / 10);
	*str = (nb % 10) + '0';
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;
	int		i;

	if (n == 0)
	{
		return (ft_strdup("0"));
	}
	else if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	len = count_fact(n);
	num = ft_calloc(len + 1, sizeof(char));
	if (!num)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		num[i++] = '-';
	}
	assign_nums(num + len - 1, n);
	return (num);
}

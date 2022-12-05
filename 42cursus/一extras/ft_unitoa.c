/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:41:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/17 18:56:33 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftprintf.h"

static unsigned int	nbr_of_digits(unsigned int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_unitoa(unsigned int n)
{
	char	*string;
	int		i;
	int		digits;

	if (n == 0)
		return (ft_strdup("0"));
	digits = nbr_of_digits(n);
	i = digits;
	string = (char *) malloc(digits + 1);
	if (!string)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		string[0] = '-';
	}
	while (n > 0)
	{
		string[--i] = n % 10 + 48;
		n = n / 10;
	}
	string[digits] = '\0';
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 19:01:40 by amak              #+#    #+#             */
/*   Updated: 2022/11/16 21:57:28 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	calc_lentgh(int n)
{
	int		places;

	places = 0;
	if (n == 0)
		places++;
	else if (n > 0)
	{
		while (n >= 10)
		{
			n = n / 10;
			places++;
		}
		places++;
	}
	return (places);
}

char	*ft_itoa(int n)
{
	char	*result;	
	int		is_negative;
	int		length;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	length = calc_lentgh(n) + is_negative;
	result = (char *)ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	while (length > 0)
	{
		result[length - 1] = (n % 10) + 48;
		n = n / 10;
		length--;
	}
	if (is_negative == 1)
		result[0] = '-';
	return (result);
}

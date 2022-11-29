/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:08:08 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/23 02:16:23 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	get_lenght_(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	size_t			i;
	size_t			nbr_digi;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = get_lenght_(n);
	nbr_digi = i;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{	
		n = -n;
		res[0] = '-';
	}
	while (n > 0)
	{
		res[--nbr_digi] = n % 10 + 48;
		n = n / 10;
	}
	res[i] = '\0';
	return (res);
}

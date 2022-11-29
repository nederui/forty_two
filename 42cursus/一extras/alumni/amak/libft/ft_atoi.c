/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 00:13:19 by amak              #+#    #+#             */
/*   Updated: 2022/10/29 16:34:43 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (((c >= 9) && (c <= 13)) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	pos;
	int	sign;
	int	res;

	pos = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(nptr[pos]))
		pos++;
	if (nptr[pos] == '-' || nptr[pos] == '+')
	{	
		if (nptr[pos] == '-' )
			sign = -1;
		pos++;
	}
	while (nptr[pos] >= '0' && nptr[pos] <= '9')
	{
		res = (res * 10) + (nptr[pos] - 48);
		pos++;
	}
	res = res * sign;
	return (res);
}

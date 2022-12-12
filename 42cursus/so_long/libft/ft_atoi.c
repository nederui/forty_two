/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:23:22 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:37:07 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	integer;

	i = 0;
	integer = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		integer = integer * 10 + (str[i] - 48);
		i++;
	}
	return ((int)integer * sign);
}

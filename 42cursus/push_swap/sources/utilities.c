/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:42:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/21 18:56:01 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	atoi_pswap(char *str)
{
	int		i;
	int		sign;
	long	integer;

	i = 0;
	integer = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (ft_issign(str[i]))
		return ((long)error_);
	while (str[i] && !ft_isspace(str[i]))
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	return ((long)integer * sign);
}

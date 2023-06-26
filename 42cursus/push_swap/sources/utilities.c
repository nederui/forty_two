/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:42:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/26 20:17:28 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
this function keep all the data of its corresponding structure static during 
the runtime of the program; it allows the access of this structs' data to
all the functions that need to read from / modify them, by a simple call of
"swap()", as it returns the address of the struct it is assigned to (t_swap)
*/
t_ps	*p_s(void)
{
	static t_ps	push_swap;

	return (&push_swap);
}

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
		error_();
	while (str[i] && !ft_isspace(str[i]))
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	return (integer * sign);
}

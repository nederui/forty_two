/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_real_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:34:58 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/22 22:34:59 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	the_real_atoi(const char	*str)
{
	int	i;
	int	sign;
	int	integer;

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
	while (str[i] > 47 && str[i] < 58)
	{
		integer = integer * 10 + (str[i] - 48);
		i++;
	}
	return (integer * sign);
}

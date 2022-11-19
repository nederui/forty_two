/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 17:32:37 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/24 17:32:38 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	number;

	number = 1;
	if (power < 0)
		return (0);
	while (power != 0)
	{
		number = number * nb;
		power--;
	}
	return (number);
}

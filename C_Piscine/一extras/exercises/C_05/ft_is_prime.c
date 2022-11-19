/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:52:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/25 14:52:28 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	number;

	number = 2;
	if (nb < 2)
		return (0);
	while (number <= nb / 2)
	{
		if ((nb % number) == 0)
			return (0);
		number++;
	}
	return (1);
}

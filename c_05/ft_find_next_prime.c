/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:52:51 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/25 14:52:52 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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


int	ft_find_next_prime(int nb)
{
	while (ft_is_prime(nb) == 0)
		nb++;
	return (nb);
}


int	main(void)
{
	printf("%d \n", ft_find_next_prime(2));
	printf("%d \n", ft_find_next_prime(6));
	printf("%d \n", ft_find_next_prime(10));
	printf("%d \n", ft_find_next_prime(65));
	printf("%d \n", ft_find_next_prime(23));
	printf("%d \n", ft_find_next_prime(54));
	printf("%d \n", ft_find_next_prime(15));
	printf("%d \n", ft_find_next_prime(32));
}

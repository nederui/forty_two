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

int	main(void)
{
	printf("%i primo \n", ft_is_prime(7));
	printf("%i primo \n", ft_is_prime(19));
	printf("%i primo \n", ft_is_prime(11));
	printf("%i primo \n", ft_is_prime(5));
	printf("%i normal \n", ft_is_prime(20));
	printf("%i normal \n", ft_is_prime(14));
	printf("%i normal \n", ft_is_prime(65));
	printf("%i normal \n", ft_is_prime(26));
}

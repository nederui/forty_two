/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:41:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/31 14:22:58 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// static char	*ft_strrev(char *string)
// {
// 	size_t	i;
// 	size_t	len_string;
// 	char	pouch;

// 	i = 0;
// 	if (string[i] == '-')
// 		i++;
// 	len_string = ft_strlen(string) - 1;
// 	while (i < len_string)
// 	{
// 		pouch = string[len_string];
// 		string[len_string] = string[i];
// 		string[i] = pouch;
// 		i++;
// 		len_string--;
// 	}
// 	return (string);
// }

static int	nbr_of_digits(int n)
{
	int	digits;

	digits = 0;
	if (n < 0)
	{
		n = -n;
		digits++;
	}
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;
	int		digits;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	digits = nbr_of_digits(n);
	i = digits;
	string = (char *) malloc(digits + 1);
	if (!string)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		string[0] = '-';
	}
	while (n > 0)
	{
		string[--i] = n % 10 + 48;
		n = n / 10;
	}
	string[digits] = '\0';
	return (string);
}

// Parameters		n: the integer to convert.

// Return value	The string representing the integer.
// 				NULL if the allocation fails.

// External functs. malloc

// Description		Allocates (with malloc(3)) and returns a string
// 				representing the integer received as an argument.
// 				Negative numbers must be handled.

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(2147483647));
// 	return (0);
// }

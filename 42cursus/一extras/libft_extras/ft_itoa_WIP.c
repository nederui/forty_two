/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_WIP.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:41:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/14 21:07:03 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

static char	*ft_itoa(int n)
{
	char	*string;

	string = (char *) malloc(sizeof(char) * 2);
	if (string)
	{	
		if (n == -2147483648)
		{
			free(string);
			return (ft_strdup("-2147483648"));
		}
		else if (n < 0)
		{
			string[0] = '-';
			string[1] = '\0';
			string = ft_strjoin(string, ft_itoa(-n));
		}
		else if (n > 9)
			string = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
		else if (n >= 0 && n < 10)
		{
			string[0] = n + 48;
			string[1] = '\0';
		}
	}
	return (string);
}

// Parameters		n: the integer to convert.

// Return value	The string representing the integer.
// 				NULL if the allocation fails.

// External functs. malloc

// Description		Allocates (with malloc(3)) and returns a string
// 				representing0 the integer received as an argument.
// 				Negative numbers must be handled.

// char	*ft_itoa(int n)
// {
// 	char	*string;
	
// 	if (n > -1)
// 		return (ft_itoa_main(n));
// 	else
// 	{
// 		string = ft_itoa_main(n);
// 		string[0] = '-';
// 		return (string);	
// 	}
// }

// int	main(void)
// {
// 	char	*string = ft_itoa(-1234);
// 	printf("%s\n", string);
// 	free(string);
// 	return (0);
// }

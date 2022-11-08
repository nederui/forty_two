/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:37:25 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:37:25 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	intlen(long ln)
{
	int	len;

	len = 0;
	if (ln < 0)
	{
		ln = -ln;
		len++;
	}
	if (ln == 0)
	{
		return (1);
	}
	while (ln > 0)
	{
		ln /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	long	ln;
	int		len;
	int		i;

	ln = n;
	len = intlen(ln);
	i = len - 1;
	num = malloc(len + 1);
	if (n < 0)
	{
		ln = -ln;
		num[0] = '-';
	}
	while (ln > 0)
	{
		num[i] = (ln % 10) + '0';
		ln /= 10;
		i--;
	}
	num[len] = '\0';
	if (!n)
		num[0] = 0 + 48;
	return (num);
}

	// if (!num)
	// 	return (0);
// int main(void)
// {
//     char *str;

//     str = ft_itoa(2147483647);
//     printf("%s", str);
// }

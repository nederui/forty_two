/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 04:31:27 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/18 09:24:56 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
    char c;
    c = '1';
    printf("Result when numeric character is passed: %d", ft_isdigit(c));

    c = '{';
    printf("\nResult when non-numeric character is passed: %d\n", ft_isdigit(c));

    return 0;
}
*/
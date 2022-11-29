/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 07:06:08 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/18 09:25:54 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i >= 32 && i <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
int main()
{
    char c;

    c = 'Q';
    printf("Result when a printable character %c is passed to isprint(): \
	%d\n", c, ft_isprint(c));

    c = '\n';
    printf("\nResult when a control character %c is passed to isprint(): \
	%d\n", c, ft_isprint(c));
    return 0;
}
*/

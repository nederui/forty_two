/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:43:24 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/04 04:04:21 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{	
	if ((97 <= i && i <= 122) || (65 <= i && i <= 90))
		return (1);
	return (0);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void){
	
	char	c;
	
	c = ';';
	ft_isalpha(c);
	printf("Result when value is passed: %d\n", ft_isalpha(c));
	return (0);
}
*/

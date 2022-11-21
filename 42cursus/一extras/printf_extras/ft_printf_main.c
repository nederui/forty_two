/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:01:46 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/21 02:38:30 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// int		a = 2130;
	// char	x = 'A';
	char	*s = NULL;
	// unsigned int	u = 2222222222;
	// int	k = 35515000;

	// ft_printf("%%\n%i\n%c\n%u\n%x\n%X\n%p\n%s", a, x, u, k, k, s, s);
	// ft_printf("\n\n");
	ft_printf("%p\n%s", s, s);
	ft_printf("\n");
	printf("%p\n%s", s, s);
	return (0);
}

//
// %p in printf formats a pointer type. This is going to distinguish
// a null-pointer and print (nil) because it is a special value in the 
// context of a pointer.
//
// NULL is a macro defined as 0 or ((void *) 0), so if you set 
// a pointer to NULL it's exactly the same as setting it to 0. 
// This works for the purposed of declaring null pointers because 
// the memory at address 0 will never be allocated to your program.
//

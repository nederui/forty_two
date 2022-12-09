/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:35:50 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:32:57 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include <unistd.h>

/* 
this function is a modified version of the original ft_putchar(), to match
ft_printf()'s RETURN value: the number of bytes written
*/

int	ft_putchar_pf(char c)
{
	return (write(1, &c, 1));
}

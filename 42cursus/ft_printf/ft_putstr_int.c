/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:35:34 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 22:17:01 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_int(char *s)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		bytes = bytes + write(1, &s[i], 1);
		i++;
	}
	return (bytes);
}

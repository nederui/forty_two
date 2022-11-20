/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:35:34 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 20:08:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ftprintf.h"

int	ft_putstr_int(char *ptr)
{
	int	i;
	int	bytes;

	i = 0;
	bytes = 0;
	while (ptr[i])
	{
		bytes = bytes + write(1, &ptr[i], 1);
		i++;
	}
	return (bytes);
}

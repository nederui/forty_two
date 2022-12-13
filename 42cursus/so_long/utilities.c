/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 16:06:14 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/12 21:48:15 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// a variation of ft_strlen, to exlude the '\n' character
int	ft_strlen_sl(char *string)
{
	int	len;

	len = 0;
	while (string && string[len] && string[len] != '\n')
		++len;
	return (len);
}

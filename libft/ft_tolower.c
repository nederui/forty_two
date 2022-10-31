/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:23:40 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/31 01:54:18 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The tolower() function converts an upper-case letter to the corresponding
lower-case letter. The argument must be representable as an unsigned char or
the value of EOF.
*/

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

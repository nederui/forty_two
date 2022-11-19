/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 23:24:11 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/13 23:25:30 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b > 0)
	{
		*div = (a / b);
		*mod = (a % b);
	}
}

// b > 0 is a must condition because, according to Math, 
// one cannot divide a number by zero.
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
	int	treasure_chest;
	int	treasure_trove;

	div = &treasure_chest;
	mod = &treasure_trove;
	*div = (a / b);
	*mod = &(a % b);
}

//	This function divides parameters a by b and stores the result in the int pointed by div. 
//	It also stores the remainder of the division of a by bin the int pointed by mod.
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 20:57:11 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/13 23:19:59 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	pouch;

	pouch = *a;
	*a = *b;
	*b = pouch;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:14:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 02:58:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_it(void)
{
	if (!is_it_sorted(p_s()->stack_a))
	{
		if (p_s()->stack_len == 2)
			sa();
		else if (p_s()->stack_len == 3)
			sort_three();
		else if (p_s()->stack_len <= 5)
			sort_four_five();
		else
			sir_sort_a_lot();
	}
	else	//////////////////////////////////
		ft_printf("\nalready sorted.\n");	//
			//////////////////////////////////
}

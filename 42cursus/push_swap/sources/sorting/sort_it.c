/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:14:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/26 21:08:44 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_it(void)
{
	if (!is_it_sorted(p_s()->stack_a))
	{
		ft_printf("BEFORE:\n");			/////////////////////////////
		print_stacks();
		if (p_s()->stack_len == 2)
		{
			ft_printf("sorting two.\n");			/////////////////////////////
			sa();
		}
		else if (p_s()->stack_len == 3)
		{
			ft_printf("sorting three.\n");			/////////////////////////////
			sort_three();
			ft_printf("three sorted.\n");			/////////////////////////////
		}
		else if (p_s()->stack_len <= 5)
		{
			ft_printf("sorting four or five.\n");			/////////////////////////////
			sort_four_five();
		}
		else
		{
			ft_printf("sorting a lot.\n");			/////////////////////////////
			sir_sort_a_lot();
		}
	}
	else	//////////////////////////////////
		ft_printf("\nalready sorted.\n");	//
			//////////////////////////////////
}

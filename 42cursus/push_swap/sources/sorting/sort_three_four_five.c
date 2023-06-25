/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_four_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 03:02:06 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(void)
{
	t_list  *first;
	t_list  *second;
	t_list  *third;
	
	first = p_s()->stack_a;
	second = first->next;
	third = second->next;
	if ((t_ptr)third->content > (t_ptr)second->content)
	{
		if ((t_ptr)third->content > (t_ptr)first->content)
			sa();
		else
			ra();
	}
	else
	{
		if ((t_ptr)first->content > (t_ptr)second->content)
			sa();
		rra();
		if ((t_ptr)third->content > (t_ptr)first->content)
			sa();
	}
}

void    sort_four_five(void)
{
	push_lowest_to_b();
	if (p_s()->stack_len == 5)
		push_lowest_to_b();
	sort_three();
	pa();
	pa();
}

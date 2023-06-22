/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/22 17:16:01 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void		sort_three(void)
{
	t_list  *first;
	t_list  *second;
	t_list  *third;
	
	first = swap()->head_a;
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

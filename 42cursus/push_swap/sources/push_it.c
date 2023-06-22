/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:14:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/22 04:34:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		is_it_sorted(void)
{
	t_list	*ptr;

	if (!swap()->head_a)
		return (0);
	ptr = swap()->head_a;
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);	
}

void	push_it(void)
{
	if (!is_it_sorted())
	{
		if (swap()->stack_len == 2)
			sa();
		else if (swap()->stack_len == 3)
			sort_three();
		else if (swap()->stack_len <= 5)
			sort_four_five();
		else
			sir_sort_a_lot();
	}
}

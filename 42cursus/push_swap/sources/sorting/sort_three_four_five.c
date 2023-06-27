/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_four_five.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 01:41:35 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sort_three(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	// ft_printf("sorting three.\n");			/////////////////////////////
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

void	sort_four_five(void)
{
	int	stack_size;

	stack_size = ft_lstsize(p_s()->stack_a);
	// ft_printf("sorting four.\n");			/////////////////////////////
	to_the_top(find_lowest_number(p_s()->stack_a));
	pb();
	// print_stacks();
	if (stack_size == 5)
	{
		// ft_printf("sorting five.\n");			/////////////////////////////
		to_the_top(find_lowest_number(p_s()->stack_a));
		pb();
		// print_stacks();
	}
	if (!is_it_sorted(p_s()->stack_a))
	{
		// print_stacks();
		sort_three();
	}
	pa();
	pa();
}

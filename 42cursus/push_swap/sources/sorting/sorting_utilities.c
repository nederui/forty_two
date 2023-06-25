/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:05:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 02:59:17 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	place_lowest_on_top(int position)
{
	if (position > 3)
	{
		while (position <= ft_lstsize(p_s()->stack_a))
		{
			rra();
			position++;
		}
	}
	else
		while (position != 1)
		{
			ra();
			position--;
		}
}

int	find_lowest_pos(t_list *lst)
{
	int	position;

	if (!lst)
		return (FAILURE);
	position = 1;
	while (lst)
	{
		if ((t_ptr)lst->content == p_s()->lowest_value)
			return (position);
		lst = lst->next;
		position++;
	}
	return (SUCCESS);
}

void	find_lowest_value(void *value)
{
	if ((t_ptr)value < p_s()->lowest_value)
		p_s()->lowest_value = (t_ptr)value;
}

void	push_lowest_to_b(void)
{
	p_s()->lowest_value = (t_ptr)p_s()->stack_a->content;
	ft_lstiter(p_s()->stack_a, find_lowest_value);
	place_lowest_on_top(find_lowest_pos(p_s()->stack_a));
	pb();
}

int	is_it_sorted(t_list *stack)
{

	if (!stack)
		return (0);
	while (stack->next)
	{
		if ((t_ptr)stack->content > (t_ptr)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);	
}

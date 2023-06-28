/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:05:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 15:53:56 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_proximity_of_b(int index)
{
	if (index > ft_lstsize(p_s()->stack_b) / 2)
		return (GO_DOWN);
	else
		return (GO_UP);
}

void	to_the_top_of_b(int index)
{
	if (get_proximity_of_b(index) == GO_DOWN)
		while (index != ft_lstsize(p_s()->stack_b))
		{
			rrb();
			index++;
		}
	else
		while (index)
		{
			rb();
			index--;
		}
}

int	get_proximity(int index)
{
	if (index > ft_lstsize(p_s()->stack_a) / 2)
		return (GO_DOWN);
	else
		return (GO_UP);
}

void	to_the_top(int index)
{
	if (get_proximity(index) == GO_DOWN)
		while (index != ft_lstsize(p_s()->stack_a))
		{
			rra();
			index++;
		}
	else
		while (index)
		{
			ra();
			index--;
		}
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

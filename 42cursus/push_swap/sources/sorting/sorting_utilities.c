/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:05:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/29 17:29:35 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// calculates the current node's distance to stack_b's ends (front / back)
int	get_proximity_of_b(int index)
{
	if (index > ft_lstsize(p_s()->stack_b) / 2)
		return (GO_DOWN);
	else
		return (GO_UP);
}

// takes the current node (number) to the front end (top) of stack_b
void	to_the_top_of_b(int index)
{
	if (get_proximity_of_b(index) == GO_DOWN)
	{
		while (index != ft_lstsize(p_s()->stack_b))
		{
			rrb();
			index++;
		}
	}
	else
	{
		while (index)
		{
			rb();
			index--;
		}
	}
}

// calculates the current node's distance to stack_a's ends (front / back)
int	get_proximity(int index)
{
	if (index > ft_lstsize(p_s()->stack_a) / 2)
		return (GO_DOWN);
	else
		return (GO_UP);
}

// takes the current node (number) to the front end (top) of stack_a
void	to_the_top(int index)
{
	if (get_proximity(index) == GO_DOWN)
	{
		while (index != ft_lstsize(p_s()->stack_a))
		{
			rra();
			index++;
		}
	}
	else
	{
		while (index)
		{
			ra();
			index--;
		}
	}
}

/*
goes through the stack, comparing each node's content to it's next's,
checking if the stack is already sorted
*/
int	is_it_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if ((t_ptr)stack->content > (t_ptr)stack->next->content)
			return (FAILURE);
		stack = stack->next;
	}
	return (SUCCESS);
}

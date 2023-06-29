/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:54:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/29 18:20:34 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
compares the lowest number found in stack_a and the highest number
found in stack_b
*/
int	validate_last_chunk(void)
{
	int	lowest_a;
	int	highest_b;

	lowest_a = get_number(p_s()->stack_a, find_lowest_number(p_s()->stack_a));
	highest_b = get_number(p_s()->stack_b, find_highest_number(p_s()->stack_b));
	if (lowest_a < highest_b)
		return (0);
	else
		return (1);
}

/*
keeps pushing the lowest numbers to stack_b, until stack_a is left with
the highest 1/2/3/4/5 number(s) of the whole stack; validate_last_chunk() ensures
that the all numbers in stack_b are lower than all numbers found in stack_a
*/
void	push_highest_chunk(void)
{
	while (ft_lstsize(p_s()->stack_a) > 5 || !validate_last_chunk())
	{
		to_the_top(find_lowest_number(p_s()->stack_a));
		pb();
	}
	if (!is_it_sorted(p_s()->stack_a))
	{
		if (ft_lstsize(p_s()->stack_a) == 2)
			sa();
		else if (ft_lstsize(p_s()->stack_a) == 3)
			sort_three();
		else
			sort_four_five();
	}
}

/*
finds every number in stack_a that is lower or equal to ref_nbr (the current
chunk's limit) and pushes it to the top of stack_b; it also pushes same amount
of numbers from clone_a to clone_b to keep the reference to our chunks updated;
*/
int	push_lowest_chunk(t_list *stack, int ref_nbr)
{
	int	index;

	if (!stack)
		return (0);
	index = 0;
	while (stack)
	{
		if ((t_ptr)stack->content <= ref_nbr)
		{
			to_the_top(index);
			pb();
			push(&p_s()->clone_a, &p_s()->clone_b);
			return (1);
		}
		index++;
		stack = stack->next;
	}
	return (0);
}

// finds the value of the chunk's lowest limit (to serve as reference)
int	find_ref_nbr(t_list *stack)
{
	int	index;

	index = 0;
	while (stack->next && index != p_s()->chunk_size - 1)
	{
		stack = stack->next;
		index++;
	}
	return ((t_ptr)stack->content);
}

// sets the number of chunks (and their size) for stack_a to be divided into
int	set_chunks(int chunks)
{
	if (p_s()->stack_len <= 100)
		chunks = 4;
	else if (p_s()->stack_len <= 200)
		chunks = 8;
	else
		chunks = p_s()->stack_len / 35;
	p_s()->chunk_size = p_s()->stack_len / chunks;
	if (p_s()->chunk_size * chunks < p_s()->stack_len)
		while (p_s()->chunk_size * chunks < p_s()->stack_len)
			chunks++;
	return (chunks);
}

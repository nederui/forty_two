/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:54:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 16:06:12 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_highest_chunk(void)
{
	while (!is_it_sorted(p_s()->stack_a) && ft_lstsize(p_s()->stack_a) > 5)
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

int	push_lowest_chunk(t_list *stack, int key_nbr)
{
	int	index;

	if (!stack)
		return (0);
	index = 0;
	while (stack)
	{
		if ((t_ptr)stack->content <= key_nbr)
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

int	set_chunks(int chunks)
{
	if (p_s()->stack_len <= 100)
		chunks = 5;
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

int	find_ref_nbr(t_list *stack)
{
	int		index;

	index = 0;
	while (stack->next && index != p_s()->chunk_size - 1)
	{
		stack = stack->next;
		index++;
	}
	return ((t_ptr)stack->content);
}

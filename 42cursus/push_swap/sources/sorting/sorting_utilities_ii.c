/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:54:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/26 01:05:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_highest_chunk(void)
{
	while (!is_it_sorted(p_s()->stack_a) && ft_lstsize(p_s()->stack_a) > 5)
		to_the_top(find_lowest_number(p_s()->stack_a));
	if (!is_it_sorted(p_s()->stack_a))
		sort_four_five();
}

void	push_lowest_chunk(t_list **stack, int key_nbr)
{
	int	index;

	index = 0;
	while (*stack)
	{
		if ((t_ptr)(*stack)->content <= key_nbr)
		{
			to_the_top(get_proximity(index));
			pb();
			index++;
		}
		*stack = (*stack)->next;
	}
}

int	find_ref_nbr(t_list **stack)
{
	int		index;

	index = 0;
	while ((*stack)->next && index != p_s()->chunk_size)
	{
		*stack = (*stack)->next;
		index++;
	}
	return ((t_ptr)(*stack)->content);
}

int	set_chunks(int chunks)
{
	if (p_s()->stack_len < 100)
		chunks = 4;
	else if (p_s()->stack_len < 200)
		chunks = 8;
	else
		chunks = p_s()->stack_len / 25;
	if (p_s()->stack_len % chunks != 0)
		chunks += 1;
	return (chunks);
}

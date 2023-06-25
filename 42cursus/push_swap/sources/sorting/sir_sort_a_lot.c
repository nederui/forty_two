/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sir_sort_a_lot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:35 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 19:22:32 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// void	push_all_back_to_a()
// {
// }

void	push_highest_chunk(void)
{
	while (!is_it_sorted(p_s()->stack_a) && ft_lstsize(p_s()->stack_a) > 5)
		make_it_to_the_top(find_lowest_number(p_s()->stack_a));
	if (!is_it_sorted(p_s()->stack_a))
		sort_four_five();
}

void	push_lowest_chunk(t_list **stack, int key_nbr)
{
	int	index;

	index = 0;
	while ((t_ptr)(*stack)->content != key_nbr)
	{
		if ((t_ptr)(*stack)->content < key_nbr)
		{
			make_it_to_the_top(get_proximity(index));
			pb();
			index++;
		}
		*stack = (*stack)->next;
	}
}

int	find_key_nbr(t_list **stack)
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

void	sort_clone(t_list *stack)
{
	int	temp;

	if (!stack)
		return ;
	while (stack->next)
	{
		if ((t_ptr)stack->content > (t_ptr)stack->next->content)
		{
			temp = (t_ptr)stack->content;
			stack->content = stack->next->content;
			stack->next->content = (void *)(intptr_t)temp;
		}
		stack = stack->next;
	}
}

void	set_chunk_size(void)
{
	if (p_s()->stack_len < 100)
		p_s()->chunks = 4;
	else if (p_s()->stack_len < 200)
		p_s()->chunks = 8;
	else
		p_s()->chunks = 16;
	p_s()->chunk_size = p_s()->stack_len / p_s()->chunks;
	if (p_s()->stack_len % 2 != 0)
		p_s()->chunks += 1;
}

void	sir_sort_a_lot(void)
{
	set_chunk_size();
	while (!is_it_sorted(p_s()->clone_a))
		sort_clone(p_s()->clone_a);
	while (p_s()->chunks != 1 && !is_it_sorted(p_s()->stack_a))
	{
		push_lowest_chunk(&p_s()->clone_a, find_key_nbr(&p_s()->clone_a));
		p_s()->chunks--;
	}
	if (!is_it_sorted(p_s()->stack_a))
		push_highest_chunk();
	// push_highest_to_a();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sir_sort_a_lot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:35 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/26 01:06:04 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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

void	sir_sort_a_lot(void)
{
	// int	chunks;

	// chunks = set_chunks(0);
	// p_s()->chunk_size = p_s()->stack_len / chunks;
	// while (!is_it_sorted(p_s()->clone_a))
	// 	sort_clone(p_s()->clone_a);
	ft_printf("chunks: %d\nlen: %d\nsize: %d\n", chunks, p_s()->stack_len, p_s()->chunk_size);
	// while (chunks != 1 && !is_it_sorted(p_s()->stack_a))
	// {
	// 	push_lowest_chunk(&p_s()->clone_a, find_ref_nbr(&p_s()->clone_a));
	// 	chunks--;
	// }
	if (!is_it_sorted(p_s()->stack_a))
		push_highest_chunk();
	while (p_s()->stack_b)
	{
		to_the_top(find_highest_number(p_s()->stack_b));
		pa();
	}
}

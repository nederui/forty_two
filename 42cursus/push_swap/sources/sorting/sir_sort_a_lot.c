/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sir_sort_a_lot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:35 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 00:38:43 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	print_clone(void)
{	
	t_list	*clone;
	t_list	*clone_b;

	clone = p_s()->clone_a;
	clone_b = p_s()->clone_b;
	ft_printf("clone a       clone b\n");
	while (clone || clone_b)
	{
		if (clone)
		{
			ft_printf("%d       ", clone->content);
			clone = clone->next;
		}
		else
			ft_printf("       ");
		if (clone_b)
		{
			ft_printf("%d\n", clone_b->content);
			clone_b = clone_b->next;
		}
		else
			ft_printf("\n");
	}
	ft_printf("\n");
}

void	sort_clone(t_list *stack)
{
	int	temp;

	ft_printf("sorting clone.\n");
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
	int	chunks;
	int	ref_chunks;
	int	ref_nbr;

	chunks = set_chunks(0);
	ref_chunks = chunks;
	p_s()->chunk_size = p_s()->stack_len / chunks;
	print_clone();
	while (!is_it_sorted(p_s()->clone_a))
		sort_clone(p_s()->clone_a);
	ft_printf("clone sorted. <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	print_clone();
	ft_printf("chunks: %d\nlen: %d\nsize: %d\n", chunks, p_s()->stack_len, p_s()->chunk_size);
	ref_nbr = find_ref_nbr(p_s()->clone_a);
	while (chunks != 1 && !is_it_sorted(p_s()->stack_a))
	{
		if (!push_lowest_chunk(p_s()->stack_a, ref_nbr))
		{
			ref_nbr = find_ref_nbr(p_s()->clone_a);
			chunks--;
			ft_printf("chunks: %d of %d\n", chunks, ref_chunks);
		}
	}
	if (!is_it_sorted(p_s()->stack_a))
		push_highest_chunk();
	print_stacks();
	ft_printf("<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>\n");
	while (p_s()->stack_b)
	{
		to_the_top_of_b(find_highest_number(p_s()->stack_b));
		pa();
		print_stacks();
	}
}

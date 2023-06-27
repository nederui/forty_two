/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:54:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 01:44:41 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push_highest_chunk(void)
{
	// ft_printf(">>>>>>>>>>>>> pushing HIGHEST chunk. <<<<<<<<<<<<\n");			/////////////////////////////
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
	// ft_printf("\n\ndonzo.\n\n");
}

int	push_lowest_chunk(t_list *stack, int key_nbr)
{
	int	index;

	// print_stacks();
	// ft_printf(">>>>>>>>>>>>> pushing lowest chunk.\n");			/////////////////////////////
	if (!stack)
		return (0);
	index = 0;
	while (stack)
	{
		// ft_printf("index: %d	conteudo: %d	key_nbr: %d\n", index, (t_ptr)stack->content,key_nbr);
		if ((t_ptr)stack->content <= key_nbr)
		{
			to_the_top(index);
			pb();
			push(&p_s()->clone_a, &p_s()->clone_b);
			// print_clone();
			// print_stacks();
			return (1);
		}
		index++;
		stack = stack->next;
	}
	// ft_printf("DONE\n");
	// print_stacks();
	return (0);
}

int	find_ref_nbr(t_list *stack)
{
	int		index;

	// ft_printf("finding ref number.\n");			/////////////////////////////
	index = 0;
	while (stack->next && index != p_s()->chunk_size - 1)
	{
		stack = stack->next;
		index++;
	}
	// ft_printf("found.\nref number:%d\n", (t_ptr)stack->content);			/////////////////////////////
	return ((t_ptr)stack->content);
}

int	set_chunks(int chunks)
{
	if (p_s()->stack_len < 100)
		chunks = 4;
	else if (p_s()->stack_len < 200)
		chunks = 8;
	else
		chunks = p_s()->stack_len / 25;
	// if (p_s()->stack_len % chunks != 0)
	// 	chunks++;
	p_s()->chunk_size = p_s()->stack_len / chunks;		//	WIP
	if (p_s()->chunk_size * chunks < p_s()->stack_len)	//	WIP
		chunks++;						//	WIP
	// 	chunks = p_s()->stack_len;						//	WIP
	return (chunks);
}

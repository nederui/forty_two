/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sir_sort_a_lot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:35 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 03:50:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sir_sort_a_lot(void)
{
	set_chunk_size();
	// if (p_s()->stack_len < 100)
	// 	p_s()->chunk_size =  p_s()->stack_len / 4;
	// else if (p_s()->stack_len < 200)
	// 	p_s()->chunk_size =  p_s()->stack_len / 8;
	// else
	// 	p_s()->chunk_size =  p_s()->stack_len / 16;

	clone_stack();
	sort_clone();

	sort_large_stack();
	// set_chunk_index();
	// int	counter;

	// counter = 4 / 8 / 16;
	// while (counter != 1)
	// {
	// push_lowest_chunk_to_b();
		// counter--;
	// }
	// push_highest_chunk_to_b();
	// push_highest_to_a();
}

proximity()
{
	if (index > p_s()->stack_len / 2 )
	{
		/* code */
	}
}

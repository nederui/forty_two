/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:36 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/23 17:30:09 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse(t_list **stack)
{
	t_list	*last_node;
	t_list	*secondtolast_node;

	if (!*stack)
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
	{
		secondtolast_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = *stack;
	secondtolast_node->next = NULL;
	*stack = last_node;
}

void	rra(void)
{
	reverse(&p_s()->head_a);
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	reverse(&p_s()->head_b);
	write(1, "rrb\n", 4);
}

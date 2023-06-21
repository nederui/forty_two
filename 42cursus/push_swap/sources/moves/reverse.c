/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:36 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/21 19:09:53 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rrb(void)
{
	t_list	*last_node;
	t_list	*secondtolast_node;

	if (!swap()->head_b)
		return ;
	last_node = swap()->head_b;
	while (last_node->next != NULL)
	{
		secondtolast_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = swap()->head_b;
	secondtolast_node->next = NULL;
	swap()->head_b = last_node;
	write(1, "rrb\n", 4);
}

void	rra(void)
{
	t_list	*last_node;
	t_list	*secondtolast_node;

	if (!swap()->head_a)
		return ;
	last_node = swap()->head_a;
	while (last_node->next != NULL)
	{
		secondtolast_node = last_node;
		last_node = last_node->next;
	}
	last_node->next = swap()->head_a;
	secondtolast_node->next = NULL;
	swap()->head_a = last_node;
	write(1, "rra\n", 4);
}

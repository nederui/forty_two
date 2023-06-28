/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 03:22:28 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*last_node;

	if (!*stack)
		return ;
	temp = (*stack)->next;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	(*stack)->next = NULL;
	*stack = temp;
}

void	ra(void)
{
	rotate(&p_s()->stack_a);
	write(1, "ra\n", 3);
}

void	rb(void)
{
	rotate(&p_s()->stack_b);
	write(1, "rb\n", 3);
}

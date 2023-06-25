/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:40 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 03:00:08 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(void)
{
	swap(&p_s()->stack_a);
	write(1, "sa\n", 3);
}

void	sb(void)
{
	swap(&p_s()->stack_b);
	write(1, "sb\n", 3);

}
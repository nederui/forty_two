/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:49:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/22 16:57:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pb(void)
{
	t_list	*temp;

	if (!swap()->head_a)
		return ;
	temp = swap()->head_b;
	swap()->head_b = swap()->head_a;
	swap()->head_a = swap()->head_a->next;
	swap()->head_b->next = temp;
	write(1, "pb\n", 3);
}

void	pa(void)
{
	t_list	*temp;

	if (!swap()->head_b)
		return ;
	temp = swap()->head_a;
	swap()->head_a = swap()->head_b;
	swap()->head_b = swap()->head_b->next;
	swap()->head_a->next = temp;
	write(1, "pa\n", 3);
}

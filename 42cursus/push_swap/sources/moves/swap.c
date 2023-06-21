/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:40 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/21 17:27:39 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sb(void)
{
	t_list	*temp;

	if (!swap()->head_b || !swap()->head_b->next)
		return ;
	temp = swap()->head_b;
	swap()->head_b = swap()->head_b->next;
	temp->next = swap()->head_b->next;
	swap()->head_b->next = temp;
	write(1, "sb\n", 3);
}

void	sa(void)
{
	t_list	*temp;

	if (!swap()->head_a || !swap()->head_a->next)
		return ;
	temp = swap()->head_a;
	swap()->head_a = swap()->head_a->next;
	temp->next = swap()->head_a->next;
	swap()->head_a->next = temp;
	write(1, "sa\n", 3);
}

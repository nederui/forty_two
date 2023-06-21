/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/21 17:22:07 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rb(void)
{
	t_list	*temp;
	t_list	*last_node;

	if (!swap()->head_b)
		return ;
	temp = swap()->head_b->next;
	last_node = ft_lstlast(swap()->head_b);
	last_node->next = swap()->head_b;
	swap()->head_b->next = NULL;
	swap()->head_b = temp;
	write(1, "ra\n", 3);
}

void	ra(void)
{
	t_list	*temp;
	t_list	*last_node;

	if (!swap()->head_a)
		return ;
	temp = swap()->head_a->next;
	last_node = ft_lstlast(swap()->head_a);
	last_node->next = swap()->head_a;
	swap()->head_a->next = NULL;
	swap()->head_a = temp;
	write(1, "ra\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:49:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 03:22:39 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_list **origin, t_list **destination)
{
	t_list	*temp;

	if (!*origin)
		return ;
	temp = *destination;
	*destination = *origin;
	*origin = (*origin)->next;
	(*destination)->next = temp;
}

void	pa(void)
{
	push(&p_s()->stack_b, &p_s()->stack_a);
	write(1, "pa\n", 3);
}

void	pb(void)
{
	push(&p_s()->stack_a, &p_s()->stack_b);
	write(1, "pb\n", 3);
}

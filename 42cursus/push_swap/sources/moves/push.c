/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:49:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/30 00:31:05 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_list *origin, t_list *destination)
{
	if (!origin->content)
		return ;
	destination->content = origin->content;
	origin->content = NULL;
}

void	pa(void)
{
	push(swap()->head_b, swap()->head_a);
	ft_printf("pa\n");
}

void	pb(void)
{
	push(swap()->head_a, swap()->head_b);
	ft_printf("pb\n");
}

// 2 1 3 6 5 8
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 03:53:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/22 17:22:13 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void    sort_four_five(void)
{
	t_list  *first;
	t_list  *second;
	t_list  *third;
	t_list  *fourth;
	t_list  *fifth;
	
	first = swap()->head_a;
	second = first->next;
	third = second->next;
	fourth = third->next;
	fifth = fourth->next;
}

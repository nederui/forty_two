/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:53:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/20 21:08:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//  WIP
// void	rb(void)
// {
// 	t_list	*temp;
// 	t_list	*ptr;

// 	if (!swap()->head_b)
// 		return ;
//     ptr = swap()->head_b;
//     temp = ft_lstlast(ptr);
//     temp->next = swap()->head_b;
//     swap()->head_b->next = NULL;
//     swap()->head_b = swap()->head_b->next;
// 	write(1, "rb\n", 3);
// }

//  WIP
void	ra(void)
{
	t_list	*temp;
	t_list	*ptr;

	if (!swap()->head_a)
		return ;
    ptr = swap()->head_a;
    temp = ft_lstlast(ptr);
    temp->next = swap()->head_a;
    swap()->head_a->next = NULL;
    swap()->head_a = swap()->head_a->next;
	write(1, "ra\n", 3);
}

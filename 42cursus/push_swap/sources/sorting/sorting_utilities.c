/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:05:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/23 17:13:08 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	place_lowest_on_top(int position)
{
	if (position > 3)
	{
		while (position != p_s()->stack_len + 1)
		{
			rra();
			position++;
		}
	}
	else
		while (position != 1)
		{
			ra();
			position--;
		}
}

int	find_lowest_pos(t_list *lst)
{
	int	position;

	if (!lst)
		return (FAILURE);
	position = 1;
	while (lst)
	{
		if ((t_ptr)lst->content == p_s()->lowest_value)
			return (position);
		lst = lst->next;
		position++;
	}
	return (SUCCESS);
}

void	find_lowest_value(void *value)
{
	if ((t_ptr)value < p_s()->lowest_value)
		p_s()->lowest_value = (t_ptr)value;
}

void	push_lowest_to_b(void)
{
	p_s()->lowest_value = (t_ptr)p_s()->head_a->content;
	ft_lstiter(p_s()->head_a, find_lowest_value);
	place_lowest_on_top(find_lowest_pos(p_s()->head_a));
	pb();
}

int	is_it_sorted(void)
{
	t_list	*ptr;

	if (!p_s()->head_a)
		return (0);
	ptr = p_s()->head_a;
	while (ptr->next)
	{
		if ((t_ptr)ptr->content > (t_ptr)ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);	
}

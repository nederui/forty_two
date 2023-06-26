/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:05:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/26 00:42:18 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_proximity(int index)
{
	if (index > ft_lstsize(p_s()->stack_a) / 2)
		return (REVERSE);
	else
		return (ROTATE);
}

void	to_the_top(int index)
{
	if (get_proximity(index))
	{
		while (index != ft_lstsize(p_s()->stack_a))
		{
			rra();
			index++;
		}
	}
	else
	{
		while (index)
		{
			ra();
			index--;
		}
	}
}

int	find_highest_number(t_list *lst)
{
	int	i;
	int	highest_index;
	int	highest_nbr;

	if (!lst)
		return (FAILURE);
	i = 0;
	highest_index = 0;
	highest_nbr = (t_ptr)lst->content;
	while (lst && i <= p_s()->chunk_size)
	{
		if (highest_nbr < (t_ptr)lst->content)
			highest_index = i;
		lst = lst->next;
		i++;
	}
	return (highest_index);
}

int	find_lowest_number(t_list *lst)
{
	int	i;
	int	lowest_index;
	int	lowest_nbr;

	if (!lst)
		return (FAILURE);
	i = 0;
	lowest_index = 0;
	lowest_nbr = (t_ptr)lst->content;
	while (lst)
	{
		if (lowest_nbr > (t_ptr)lst->content)
			lowest_index = i;
		lst = lst->next;
		i++;
	}
	return (lowest_index);
}

int	is_it_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if ((t_ptr)stack->content > (t_ptr)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

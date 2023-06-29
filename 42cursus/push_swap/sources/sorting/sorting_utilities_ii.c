/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities_ii.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:40:30 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/29 17:35:18 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// sorts the cloned stack with a simple 'bubble sort' algorith
void	sort_clone(t_list *stack)
{
	int	temp;

	if (!stack)
		return ;
	while (stack->next)
	{
		if ((t_ptr)stack->content > (t_ptr)stack->next->content)
		{
			temp = (t_ptr)stack->content;
			stack->content = stack->next->content;
			stack->next->content = (void *)(intptr_t)temp;
		}
		stack = stack->next;
	}
}

/*
through direct comparisson, finds the highest value in the given stack
and returns its corresponding index
 */
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
	while (lst)
	{
		if (highest_nbr < (t_ptr)lst->content)
		{
			highest_nbr = (t_ptr)lst->content;
			highest_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (highest_index);
}

/*
through direct comparisson, finds the lowest value in the given stack
and returns its corresponding index
 */
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
		{
			lowest_nbr = (t_ptr)lst->content;
			lowest_index = i;
		}
		lst = lst->next;
		i++;
	}
	return (lowest_index);
}

// gets the value found in the given index of the given stack
int	get_number(t_list *lst, int index)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst && i != index)
	{
		lst = lst->next;
		i++;
	}
	return ((t_ptr)lst->content);
}

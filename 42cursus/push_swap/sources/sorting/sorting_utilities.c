/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:05:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 00:37:59 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_proximity_of_b(int index)
{
	ft_printf("calculating proximity.\n");			/////////////////////////////
	if (index > ft_lstsize(p_s()->stack_b) / 2)
	{
		ft_printf("done. go down.\n");			/////////////////////////////
		return (GO_DOWN);
	}
	else
	{
		ft_printf("done. go up.\n");			/////////////////////////////
		return (GO_UP);
	}
}

int	get_proximity(int index)
{
	ft_printf("calculating proximity.\n");			/////////////////////////////
	if (index > ft_lstsize(p_s()->stack_a) / 2)
	{
		ft_printf("done. go down.\n");			/////////////////////////////
		return (GO_DOWN);
	}
	else
	{
		ft_printf("done. go up.\n");			/////////////////////////////
		return (GO_UP);
	}
}

void	to_the_top_of_b(int index)
{
	ft_printf("getting it to the top.\n");			/////////////////////////////
	if (get_proximity_of_b(index) == GO_DOWN)
	{
		while (index != ft_lstsize(p_s()->stack_b))
		{
			rrb();
			index++;
		}
	}
	else
	{
		while (index)
		{
			rb();
			index--;
		}
	}
	ft_printf("done.\nfinal index: %d\n", index);			/////////////////////////////
}

void	to_the_top(int index)
{
	ft_printf("getting it to the top.\n");			/////////////////////////////
	if (get_proximity(index) == GO_DOWN)
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
	ft_printf("done.\nfinal index: %d\n", index);			/////////////////////////////
}

int	find_highest_number(t_list *lst)
{
	int	i;
	int	highest_index;
	int	highest_nbr;

	ft_printf("finding highest number.\n");			/////////////////////////////
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
	ft_printf("found.\nhighest number:%d\nindex:%d\n", highest_nbr, highest_index);			/////////////////////////////
	return (highest_index);
}

int	find_lowest_number(t_list *lst)
{
	int	i;
	int	lowest_index;
	int	lowest_nbr;

	ft_printf("finding lowest number.\n");			/////////////////////////////
	if (!lst)
		return (FAILURE);
	i = 0;
	lowest_index = 0;
	lowest_nbr = (t_ptr)lst->content;
	while (lst)
	{
		ft_printf("%d %d<<<<<<<<<\n", lowest_nbr, (t_ptr)lst->content);
		if (lowest_nbr > (t_ptr)lst->content)
		{
			lowest_nbr = (t_ptr)lst->content;
			lowest_index = i;
		}
		lst = lst->next;
		i++;
	}
	ft_printf("found.\nlowest number:%d\nindex:%d\n", lowest_nbr, lowest_index);			/////////////////////////////
	return (lowest_index);
}

int	is_it_sorted(t_list *stack)
{
	if (!stack)
		return (0);
	ft_printf("checking if already sorted.\n");			/////////////////////////////
	while (stack->next)
	{
		if ((t_ptr)stack->content > (t_ptr)stack->next->content)
		{
			ft_printf("no.\nsorting.\n");			/////////////////////////////
			return (0);
		}
		stack = stack->next;
	}
	ft_printf("yes.\n");			/////////////////////////////
	return (1);
}

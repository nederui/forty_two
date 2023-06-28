/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 21:14:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 15:51:39 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sir_sort_a_lot(void)
{
	int	chunks;
	int	ref_nbr;

	chunks = set_chunks(0);
	while (!is_it_sorted(p_s()->clone_a))
		sort_clone(p_s()->clone_a);
	ref_nbr = find_ref_nbr(p_s()->clone_a);
	while (chunks != 1 && !is_it_sorted(p_s()->stack_a))
		if (!push_lowest_chunk(p_s()->stack_a, ref_nbr))
		{
			ref_nbr = find_ref_nbr(p_s()->clone_a);
			chunks--;
		}
	if (!is_it_sorted(p_s()->stack_a))
		push_highest_chunk();
	while (p_s()->stack_b)
	{
		to_the_top_of_b(find_highest_number(p_s()->stack_b));
		pa();
	}
}

void	sort_four_five(void)
{
	int	stack_size;

	stack_size = ft_lstsize(p_s()->stack_a);
	to_the_top(find_lowest_number(p_s()->stack_a));
	pb();
	if (stack_size == 5)
	{
		to_the_top(find_lowest_number(p_s()->stack_a));
		pb();
	}
	if (!is_it_sorted(p_s()->stack_a))
		sort_three();
	pa();
	pa();
}

void	sort_three(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	first = p_s()->stack_a;
	second = first->next;
	third = second->next;
	if ((t_ptr)third->content > (t_ptr)second->content)
	{
		if ((t_ptr)third->content > (t_ptr)first->content)
			sa();
		else
			ra();
	}
	else
	{
		if ((t_ptr)first->content > (t_ptr)second->content)
			sa();
		rra();
		if ((t_ptr)third->content > (t_ptr)first->content)
			sa();
	}
}

void	sort_it(void)
{
	if (!is_it_sorted(p_s()->stack_a))
	{
		if (p_s()->stack_len == 2)
			sa();
		else if (p_s()->stack_len == 3)
			sort_three();
		else if (p_s()->stack_len <= 5)
			sort_four_five();
		else
			sir_sort_a_lot();
	}
	else
		return ;
}

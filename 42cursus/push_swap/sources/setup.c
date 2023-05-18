/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:10 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/18 18:09:42 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
# include <stdint.h>

/* 
W I P 
(void *)(intptr_t)
(int)(intptr_t)

*/
int	stack_it(int number)
{
	// t_list	new_node;

	// new_node = *ft_lstnew(number);
	ft_lstadd_back(&swap()->int_lst, ft_lstnew((void *)(intptr_t)number));
	swap()->stack_len++;
	return (SUCCESS);
}

/* W I P */
int	check_duplicate(int number)
{
	t_list	*int_lst;

	int_lst = swap()->int_lst;
	if (!int_lst)
		return (FAILURE);
	while (int_lst)
	{
		if ((t_ptr)int_lst->content == number)
			return (FAILURE);
		int_lst = int_lst->next;
	}
	return (SUCCESS);
}

/*   */
int	check_digits(char *argument)
{
	int		i;

	i = 0;
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

/*   */
int	check_integer(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (FAILURE);
	return (SUCCESS);
}

/* W I P */
int	setup(char **argv)
{
	int		i;
	long	number;

	i = 0;
	swap()->status = SUCCESS;		//
	while (argv[++i])
	{
		if (!check_digits(argv[i]))
			error_(argv[i], "Invalid argument - Only numbers allowed.");
		else
		{
			number = atoi_pswap(argv[i]);
			if (!check_integer(number))
				error_(argv[i], "Invalid argument - Only integers allowed.");
			else
			{
				stack_it(number);
				if (!check_duplicate(number))
					error_(argv[i], "Invalid argument - No duplicates allowed.");
			}
		}
	}
	if (!swap()->status)
		exit_();
	return (SUCCESS);
}

/*
put them in stack a
check if any argv is a duplicate
work the stack for 5 numbers
work the stack for 'n' numbers
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:10 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/18 16:50:49 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

/* W I P */
int	stack_it(int number)
{
	t_swap	*new_node;
	
	new_node = malloc (sizeof t_swap);
	if (new_node)
	{
		swap()->next = number;

	}
	return (SUCCESS);
}

/* W I P */
// int	check_duplicate(int number)
// {

	// if (swap()->integer[index])
	// 	return (FAILURE);
	// swap()->integer[index] = 1;
	// return (SUCCESS);
// }

/* W I P */
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

/* W I P */
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
				if (!check_duplicate(number))
					error_(argv[i], "Invalid argument - No duplicates allowed.");
				else
					stack_it(number);
		}
	}
	swap()->stack_len = i - 1;		//
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
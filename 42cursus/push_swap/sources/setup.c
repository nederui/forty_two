/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:10 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/15 23:52:00 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

/* W I P */
// int	stack_it(long number)
// {
// 	ft_printf("integer: %d\n", (int)number);
// 	return (SUCCESS);
// }

/* W I P */
int	check_duplicate(long number)
{
	// if (swap()->integer[index])
	// 	return (FAILURE);
	// swap()->integer[index] = 1;
	// return (SUCCESS);
}

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

	i = 1;
	swap()->status = SUCCESS;
	while (argv[i])
	{
		if (!check_digits(argv[i]))
			error_(argv[i], "Invalid argument - Only numbers allowed.");
		else
		{
			number = atoi_pswap(argv[i]);
			if (!check_integer(number))
				error_(argv[i], "Invalid argument - Only integers allowed.");
			// stack_it(number);
			if (!check_duplicate(number))
				error_(argv[i], "Invalid argument - No duplicates allowed.");
		}
		i++;
	}
	swap()->stack_len = i - 1;
	if (!swap()->status)
		exit_();
	return (SUCCESS);
}

/*
check if all argvs are ints
check if any argv is a duplicate
put them in stack a
*/
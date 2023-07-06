/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:10 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/07/06 19:09:38 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>

// goes through the stack, checking if we have already stacked the given number
int	check_duplicate(int number)
{
	t_list	*ptr_lst;

	ptr_lst = p_s()->stack_a;
	while (ptr_lst)
	{
		if ((t_ptr)ptr_lst->content == number)
			return (FAILURE);
		ptr_lst = ptr_lst->next;
	}
	return (SUCCESS);
}

// compares the given number to a integer's limits
int	check_integer(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (FAILURE);
	return (SUCCESS);
}

int	check_arg_len(char *arg)
{
	if (ft_strlen(arg) > 11 || (ft_strlen(arg) > 10 && arg[0] != '-'))
		return (FAILURE);
	return (SUCCESS);
}

// looks for space chars in the given string
int	check_spaces(char *argument)
{
	int		i;

	i = 0;
	while (argument[i])
	{
		if (ft_isspace(argument[i]))
			return (SUCCESS);
		i++;
	}
	return (FAILURE);
}

/*
looks for any char that isn't a space, a digit or a sign; if any is found
in the given string, it returns 0 (for FAILURE)
*/
int	check_digits(char *argument)
{
	int		i;

	i = 0;
	while (argument[i])
	{
		if (!ft_isdigit(argument[i]) && !ft_isspace(argument[i]) \
		&& !ft_issign(argument[i]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

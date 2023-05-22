/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:10 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/22 18:59:15 by nfilipe-         ###   ########.fr       */
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


/* W I P */
int	check_duplicate(int number)
{
	t_list	*ptr_lst;

	ptr_lst = swap()->head_a;
	// if (!ptr_lst)
	// {
	// 	write(1, "HERE.\n", 6);
	// 	return (FAILURE);
	// }
	while (ptr_lst)
	{
		if ((t_ptr)ptr_lst->content == number)
			return (FAILURE);
		ptr_lst = ptr_lst->next;
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

/*   */
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

/*   */
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

int	validate_arguments(char **argv)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (argv[i])
	{
		if (!check_digits(argv[i]))
			return(error_());
		if (check_spaces(argv[i]))
			save_arg_array(argv[i]);
		else
		{
			number = atoi_pswap(argv[i]);
			if (!check_integer(number))
				return(error_());
			if (!check_duplicate(number))
				return(error_());
			stack_it(number);
		}
		i++;
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:50:10 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 03:01:56 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <limits.h>
#include <stdint.h>

/* 
W I P 
(void *)(intptr_t)
(int)(intptr_t)

*/

/* W I P */
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


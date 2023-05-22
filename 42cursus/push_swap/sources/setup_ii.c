/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:42:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/22 18:58:19 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_it(int number)
{
	ft_lstadd_back(&swap()->head_a, ft_lstnew((void *)(intptr_t)number));
	swap()->stack_len++;
	return (SUCCESS);
}

/*   */
int	save_arg_array(char	*argument)
{
	swap()->arguments = ft_split(argument, ' ');
	if (!swap()->arguments)
		return (error_());
	validate_arguments(swap()->arguments);
	freewillie(swap()->arguments);
	return (SUCCESS);
}

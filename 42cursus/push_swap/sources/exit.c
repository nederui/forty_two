/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:38:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/27 15:39:24 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// frees the data previously allocated for any of the program's matrix
void	freewillie(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
	array = NULL;
}

void	clear_stack(t_list *lst)
{
	t_list	*ptr_lst;

	while (lst)
	{
		ptr_lst = lst->next;
		free(lst);
		lst = ptr_lst;
	}
}

// ensures a clean program exit (including closing any open fd)
void	exit_(void)
{
	clear_stack(p_s()->stack_a);
	clear_stack(p_s()->stack_b);
	clear_stack(p_s()->clone_a);
	exit(0);
}

/*
displays a custom error message to the stderr and runs exit_() for a clean
program exit; returns 0 to exit any function in the event of an error being found
*/
int	error_(void)
{
	ft_putstr_fd("Error\n", 2);
	exit_();
	return (FAILURE);
}

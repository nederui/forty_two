/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_ii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:38:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/21 18:19:09 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ensures a clean program exit (including closing any open fd)
void	exit_(void)
{
	clear_stack(swap()->head_a);
	clear_stack(swap()->head_b);
	// if (swap()->)
	// 	freewillie(swap()->);
	// if (swap()->)
	// 	freewillie(swap()->);
	// if (swap()->)
	// 	freewillie(swap()->);
	// free(swap()->);
	// free(swap()->);
	exit(0);
}

/*
displays a custom error message to the stderr and runs exit_() for a clean
program exit; returns 0 to exit any function in the event of an error being found
*/
int	error_(void)
{
	// swap()->status = FAILURE;
	ft_putstr_fd("Error\n", 2);
	exit_();
	return (FAILURE);
}

void	print_stack(t_list *stack)
{
	t_list	*ptr_lst;

	ptr_lst = stack;
	ft_printf("STACK:\n");
	while (ptr_lst)
	{
		ft_printf("%d\n", ptr_lst->content);
		ptr_lst = ptr_lst->next;
	}
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

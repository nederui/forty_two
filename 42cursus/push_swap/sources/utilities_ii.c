/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_ii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:38:24 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/22 04:35:17 by nfilipe-         ###   ########.fr       */
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

void	print_stacks(void)
{
	t_list	*ptr_lst_a;
	t_list	*ptr_lst_b;

	ptr_lst_a = swap()->head_a;
	ptr_lst_b = swap()->head_b;
	ft_printf("a       b\n");
	while (ptr_lst_a || ptr_lst_b)
	{
		if (ptr_lst_a)
		{
			ft_printf("%d       ", ptr_lst_a->content);
			ptr_lst_a = ptr_lst_a->next;
		}
		else
			ft_printf("       ");
		if (ptr_lst_b)
		{
			ft_printf("%d\n", ptr_lst_b->content);
			ptr_lst_b = ptr_lst_b->next;
		}
		else
			ft_printf("\n");
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

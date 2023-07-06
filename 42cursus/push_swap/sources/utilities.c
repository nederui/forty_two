/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:42:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/07/04 17:20:57 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
this function keep all the data of its corresponding structure static during 
the runtime of the program; it allows the access of this structs' data to
all the functions that need to read from / modify them, by a simple call of
"swap()", as it returns the address of the struct it is assigned to (t_swap)
*/
t_ps	*p_s(void)
{
	static t_ps	push_swap;

	return (&push_swap);
}

/*
a variation of ft_atoi(), that returns a long int and does not tolerate numbers
with more than one sign
*/
long	atoi_pswap(char *str)
{
	int		i;
	int		sign;
	long	integer;

	i = 0;
	integer = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (ft_issign(str[i]))
		error_();
	while (str[i] && !ft_isspace(str[i]))
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	return (integer * sign);
}

// a debug function that prints out the content of both stacks to the STDOUT
void	print_stacks(void)
{
	t_list	*ptr_lst_a;
	t_list	*ptr_lst_b;

	ptr_lst_a = p_s()->stack_a;
	ptr_lst_b = p_s()->stack_b;
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

// a debug function that prints out the content of cloned stacks to the STDOUT
void	print_clone(void)
{
	t_list	*clone;
	t_list	*clone_b;

	clone = p_s()->clone_a;
	clone_b = p_s()->clone_b;
	ft_printf("clone a       clone b\n");
	while (clone || clone_b)
	{
		if (clone)
		{
			ft_printf("%d       ", clone->content);
			clone = clone->next;
		}
		else
			ft_printf("       ");
		if (clone_b)
		{
			ft_printf("%d\n", clone_b->content);
			clone_b = clone_b->next;
		}
		else
			ft_printf("\n");
	}
}

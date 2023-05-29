/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/30 00:15:43 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
this function keep all the data of its corresponding structure static during 
the runtime of the program; it allows the access of this structs' data to
all the functions that need to read from / modify them, by a simple call of
"swap()", as it returns the address of the struct it is assigned to (t_swap)
*/
t_swap	*swap(void)
{
	static t_swap	swap;

	return (&swap);
}

/* W I P */
int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_();
	validate_arguments(argv + 1);
	init_stack_b(0);
	ft_printf("stack lenght: %d.\n", swap()->stack_len);
	print_stack(swap()->head_a);
	print_stack(swap()->head_b);
	push_it();
	print_stack(swap()->head_a);
	print_stack(swap()->head_b);
	exit_();
	return (0);
}

/*
work the stack for 5 numbers
work the stack for 'n' numbers
*/
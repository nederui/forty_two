/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/22 15:38:13 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* W I P */
int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_();
	validate_arguments(argv + 1);
	push_it();
//////////////////////////////////////////////////////
	ft_printf("\n\nAFTER:\n", swap()->stack_len);	//
	print_stacks(); 								//
//////////////////////////////////////////////////////												//
	exit_();
	return (0);
}

/*
work the stack for 5 numbers
work the stack for 'n' numbers
*/
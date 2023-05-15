/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/15 23:00:20 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* W I P */
int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("clean_exit.\n");
		return (0);
		// exit_();
	}
	if (!setup(argv))
		return (FAILURE);
	ft_printf("stack lenght: %d.\n", swap()->stack_len);
	ft_printf("push_it.\n");
	ft_printf("clean_exit.\n");
	// push_it();
	// exit_();
	return (0);
}

/*
check if all argvs are ints			[X]
check if any argv is a duplicate	[X]
put them in stack a					[ ]
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/26 20:23:37 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* W I P */
int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_();
	validate_arguments(argc, argv + 1);
	sort_it();
//////////////////////////////////////////////////////
	ft_printf("\n\nAFTER:\n", p_s()->stack_len);	//
	print_stacks(); 								//
//////////////////////////////////////////////////////
	ft_printf("exiting program.\n");			/////////////////////////////
	exit_();
	return (0);
}

// work the stack for 'n' numbers
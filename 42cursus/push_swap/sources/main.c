/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/23 17:19:36 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* W I P */
int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_();
	validate_arguments(argv + 1);
	sort_it();
//////////////////////////////////////////////////////
	ft_printf("\n\nAFTER:\n", p_s()->stack_len);	//
	print_stacks(); 								//
//////////////////////////////////////////////////////
	exit_();
	return (0);
}

// work the stack for 'n' numbers
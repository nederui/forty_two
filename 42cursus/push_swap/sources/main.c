/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/29 16:45:12 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
the program starts with two checks: if it was given at least one argument and,
if so, if all of them are valid. 
after checking if the stack (the given list of arguments) isn't already sorted,
it sorts them through a limited amount of possible moves;
lastly, it exits the program in a clean way through exit_()
*/
int	main(int argc, char **argv)
{
	if (argc == 1)
		exit_();
	validate_arguments(argc, argv + 1);
	if (!is_it_sorted(p_s()->stack_a))
		sort_it();
	exit_();
	return (0);
}

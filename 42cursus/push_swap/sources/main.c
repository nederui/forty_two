/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:27 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/04/25 15:58:38 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*

W
I
P

*/
int	main(int argc, char **argv)
{
	if (argc < 3)
		return (error_("Invalid number of arguments."));
	if (!setup(argv))
		return (FAILURE);
	push_it();
	exit_();
	return (0);
}

/*
check if all argvs are ints
check if any argv is a duplicate
put them in stack a
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:42:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/07/06 19:10:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
creates a new node and adds the given number to the end of the stack; if the
given numbers to be sorted are 6 or more, it creates a duplicate each time in a 
different stack (clone_a); it also keeps track of the stack's total lenght
*/
int	stack_it(int argc, int number)
{
	ft_lstadd_back(&p_s()->stack_a, ft_lstnew((void *)(intptr_t)number));
	if (argc > 6)
		ft_lstadd_back(&p_s()->clone_a, ft_lstnew((void *)(intptr_t)number));
	p_s()->stack_len++;
	return (SUCCESS);
}

/*
parses the arguments in which a space char was found, validates the result
and frees the char array before exiting
*/
int	validate_arg_array(int argc, char *argument)
{
	char	**arg_array;

	arg_array = ft_split(argument, ' ');
	if (!arg_array)
		return (error_());
	validate_arguments(argc, arg_array);
	freewillie(arg_array);
	return (SUCCESS);
}

/*
goes through the char **argv, checking if all the given arguments are
unique integers; if any kind of space is detected in an argument, it
parses it into a char matrix
*/
int	validate_arguments(int argc, char **argv)
{
	int		i;
	long	number;

	i = 0;
	number = 0;
	while (argv[i])
	{
		if (!check_digits(argv[i]))
			return (error_());
		if (check_spaces(argv[i]))
			validate_arg_array(argc, argv[i]);
		else
		{
			if (!check_arg_len(argv[i]))
				return (error_());
			number = atoi_pswap(argv[i]);
			if (!check_integer(number) || !check_duplicate(number))
				return (error_());
			stack_it(argc, number);
		}
		i++;
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:42:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/30 00:26:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_stack_b(int n)
{
	n = swap()->stack_len;
	while (n > 0)
	{
		ft_lstadd_back(&swap()->head_b, ft_lstnew(NULL));
		n--;
	}
}

int	stack_it(int number)
{
	ft_lstadd_back(&swap()->head_a, ft_lstnew((void *)(intptr_t)number));
	swap()->stack_len++;
	return (SUCCESS);
}

/*   */
int	save_arg_array(char	*argument)
{
	(swap()->arguments) = ft_split(argument, ' ');
	if (!swap()->arguments)
		return (error_());
	validate_arguments(swap()->arguments);
	freewillie(swap()->arguments);
	return (SUCCESS);
}

int	validate_arguments(char **argv)
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
			save_arg_array(argv[i]);
		else
		{
			number = atoi_pswap(argv[i]);
			if (!check_integer(number))
				return (error_());
			if (!check_duplicate(number))
				return (error_());
			stack_it(number);
		}
		i++;
	}
	return (SUCCESS);
}

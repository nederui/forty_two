/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:42:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/25 03:01:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_it(int number)
{
	ft_lstadd_back(&p_s()->stack_a, ft_lstnew((void *)(intptr_t)number));
	p_s()->stack_len++;
	return (SUCCESS);
}

/*   */
int	save_arg_array(char	*argument)
{
	(p_s()->arguments) = ft_split(argument, ' ');
	if (!p_s()->arguments)
		return (error_());
	validate_arguments(p_s()->arguments);
	freewillie(p_s()->arguments);
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
			if (!check_integer(number) || !check_duplicate(number))
				return (error_());
			stack_it(number);
		}
		i++;
	}
	return (SUCCESS);
}

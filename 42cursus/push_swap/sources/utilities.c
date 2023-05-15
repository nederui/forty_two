/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:42:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/15 23:34:34 by nfilipe-         ###   ########.fr       */
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

long	atoi_pswap(char *str)
{
	int		i;
	int		sign;
	long	integer;

	i = 0;
	integer = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (str[i])
	{
		integer = integer * 10 + (str[i] - '0');
		i++;
	}
	return ((long)integer * sign);
}

/*
displays a custom error message to the stderr and runs exit_() for a clean
program exit; returns 0 to exit any function in the event of an error being found
*/
int	error_(char *argument, char *message)
{
	swap()->status = FAILURE;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(argument, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	return (FAILURE);
}

// ensures a clean program exit (including closing any open fd)
void	exit_(void)
{
	// if (swap()->)
	// 	freewillie(swap()->);
	// if (swap()->)
	// 	freewillie(swap()->);
	// if (swap()->)
	// 	freewillie(swap()->);
	// if (swap()->)
	// 	freewillie(swap()->);
	// free(swap()->);
	// free(swap()->);
	exit(0);
}

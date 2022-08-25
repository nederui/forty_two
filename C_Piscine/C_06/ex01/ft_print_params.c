/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 02:33:16 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/19 02:33:17 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (n != argc)
	{
		while (argv[n][i])
		{		
			write(1, &argv[n][i], 1);
			i++;
		}
		i = 0;
		write(1, "\n", 1);
		n++;
	}
	return (0);
}

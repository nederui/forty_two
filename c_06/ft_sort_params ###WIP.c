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

ft_putchar();

int	main(int argc, char **argv)
{
	ft_strcmp();
}

ft_sort_int_tab();


























int	main(int argc, char **argv)
{
	int		i;
	int		n;
	char	*pouch;

	i = 0;
	n = 1;
	while (argc > 2 && n < argc)
	{
		while ((argv[n][i] != '\0' && argv[n + 1][i] != '\0')
			&& (argv[n][i] == argv[n + 1][i]))
		{		
			i++;
		}
		if (argv[n][i] > argv[n + 1][i])
		{
			pouch = argv[n];
			argv[n] = argv[n + 1];
			argv[n + 1] = pouch;
			n++;
			i = 0;
		}
		else
			n++;	
	}
	n = 1;
	while (argc > 2 && n < argc)
	{
		while (argv[n][i] != '\0')
		{
			write(1, &argv[n][i], 1);
			i++;
		}
		i = 0;
		n++;
	}
	while (argc > 1 && argv[n][i] != '\0')
	{
		write(1, &argv[n][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}

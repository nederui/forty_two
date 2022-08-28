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

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &*str, 1);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*pouch;

	pouch = *a;
	*a = *b;
	*b = pouch;
}

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	// int	my_argv;
	n = 1;
	i = 0;
	while (n < argc)
	{
		if ((ft_strcmp(argv[n], argv[n + 1])) > 0)
		{
			ft_swap(&argv[n], &argv[n + 1]);
			n++;
		}
		else
			n++;
	}	
	n = 0;
	while (n < argc)
	{
		ft_putstr(argv[n]);
		write(1, "\n", 1);
		n++;
	}
	return (0);
}

// ft_sort_int_tab();

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	int		n;
// 	char	*pouch;

// 	i = 0;
// 	n = 1;
// 	while (argc > 2 && n < argc)
// 	{
// 		while ((argv[n][i] != '\0' && argv[n + 1][i] != '\0')
// 			&& (argv[n][i] == argv[n + 1][i]))
// 		{		
// 			i++;
// 		}
// 		if (argv[n][i] > argv[n + 1][i])
// 		{
// 			pouch = argv[n];
// 			argv[n] = argv[n + 1];
// 			argv[n + 1] = pouch;
// 			n++;
// 			i = 0;
// 		}
// 		else
// 			n++;	
// 	}
// 	n = 1;
// 	while (argc > 2 && n < argc)
// 	{
// 		while (argv[n][i] != '\0')
// 		{
// 			write(1, &argv[n][i], 1);
// 			i++;
// 		}
// 		i = 0;
// 		n++;
// 	}
// 	while (argc > 1 && argv[n][i] != '\0')
// 	{
// 		write(1, &argv[n][i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }

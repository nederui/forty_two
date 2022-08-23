/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:28:45 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/17 23:28:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;

// 	i = 0;
// 	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
// 		i++;
// 	return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
// }



#include <unistd.h>

void	ft_putstr(const char *str)
{
	int c;

	c = 0;
	while (str[c] != '\0')
	{
		write(1, &str[c], 1);
		c++;
	}
	write(1, "\n", 1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int c;

	c = 0;
	while ((s1[c] == s2[c]) && (s1[c] != '\0') && (s2[c] != '\0'))
		c++;
	return (s1[c] - s2[c]);
}

void	ft_swap(int *a, int *b)
{
	int aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int		main(int argc, const char **argv)
{
	int qty;
	int c;
	int d;
	int arg[argc];

	qty = 1;
	c = 1;
	while (qty < argc)
	{
		arg[qty] = qty;
		qty++;
	}
	while (c < argc)
	{
		d = c;
		while (d < argc)
		{
			if (ft_strcmp(argv[arg[c]], argv[arg[d]]) > 0)
				ft_swap(&arg[c], &arg[d]);
			d++;
		}
		ft_putstr(argv[arg[c++]]);
	}
	return (0);
}
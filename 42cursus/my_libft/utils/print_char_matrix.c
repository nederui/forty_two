/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:03:21 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/22 18:15:35 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_char_matrix(char **matrix)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			write(1, &matrix[y][x], 1);
			++x;
		}
		++y;
		if (matrix[y])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}
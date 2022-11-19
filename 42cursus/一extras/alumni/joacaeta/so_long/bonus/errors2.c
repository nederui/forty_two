/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:08:01 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/27 02:24:15 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	error_message(char	*message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putstr_fd("\n", 1);
	no_leaks_map();
	exit(0);
}

void	check_elem(int x, int y)
{
	if (game()->map.map[y][x] == 'E')
	{
		game()->elems.exit++;
		game()->exitx = x;
		game()->exity = y;
	}
	else if (game()->map.map[y][x] == 'P')
	{
		game()->elems.pos++;
		game()->posx = x;
		game()->posy = y;
	}
	else if (game()->map.map[y][x] == 'C')
		game()->elems.col++;
	else if (game()->map.map[y][x] == '1')
		game()->elems.wall++;
	else if (game()->map.map[y][x] == '0')
		game()->elems.empty++;
	else if (game()->map.map[y][x] != 'F')
		error_message("Invalid element");
}

int	elem_limits(void)
{
	if (game()->elems.pos != 1 || game()->elems.exit != 1)
		return (0);
	if (game()->elems.col < 1 || game()->elems.wall < 1 || \
		game()->elems.empty < 1)
		return (0);
	return (1);
}

void	elements(void)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game()->map.height)
	{
		x = 0;
		while (x < game()->map.width)
		{
			check_elem(x, y);
			x++;
		}
		y++;
	}
	if (!elem_limits())
		error_message("Elements missing, or more than allowed");
}

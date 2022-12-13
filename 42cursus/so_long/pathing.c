/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:21:14 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/13 16:44:31 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_pathing(t_map map, t_gameObject player)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < map.height)
	{
		ft_printf("%s", map.matrix[i]);
		++i;
	}
	ft_printf("\n\n");
	x = player.x_pos[0];
	y = player.y_pos[0];
	while (x < map.width - 1 && map.matrix[y][x + 1] != '1')
	{
		if (map.matrix[y][x + 1] == '0' ||
			map.matrix[y][x + 1] == 'C')
			map.matrix[y][x + 1] -= 1;
		if (map.matrix[y][x - 1] == '0' ||
			map.matrix[y][x - 1] == 'C')
			map.matrix[y][x - 1] -= 1;
		if (map.matrix[y + 1][x] == '0' ||
			map.matrix[y + 1][x] == 'C')
			map.matrix[y + 1][x] -= 1;
		if (map.matrix[y - 1][x] == '0' ||
			map.matrix[y - 1][x] == 'C')
			map.matrix[y - 1][x] -= 1;
		++x;
	}
	// ft_printf("player.starting.pos:\nx: [%d]\ny:[%d]\n", player.x_pos[0], player.y_pos[0]);
	while (x > 1 && map.matrix[y][x - 1] != '1')
	{
		ft_printf("player.current.pos:\nx: [%d]\ny:[%d]\n\n", x, y);
		if (map.matrix[y][x + 1] == '0' ||
			map.matrix[y][x + 1] == 'C')
			map.matrix[y][x + 1] -= 1;
		if (map.matrix[y][x - 1] == '0' ||
			map.matrix[y][x - 1] == 'C')
			map.matrix[y][x - 1] -= 1;
		if (map.matrix[y + 1][x] == '0' ||
			map.matrix[y + 1][x] == 'C')
			map.matrix[y + 1][x] -= 1;
		if (map.matrix[y - 1][x] == '0' ||
			map.matrix[y - 1][x] == 'C')
			map.matrix[y - 1][x] -= 1;
		--x;
	}

	
	// if (map.matrix[player.y_pos[0]][player.x_pos[0] + 1] == '0')
	i = 0;
	while (i < map.height)
	{
		ft_printf("%s", map.matrix[i]);
		++i;
	}
	ft_printf("\n");
	return (0);
}

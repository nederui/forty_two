/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:09:05 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/22 23:49:22 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	check_coords(t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return (0);
	if (map->tmp[y][x] != '0' && map->tmp[y][x] != 'C')
		return (0);
	map->tmp[y][x] = 'P';
	return (1);
}

void	tmp_path(t_map *map, int x, int y)
{
	if (check_coords(map, x -1, y))
		tmp_path(map, x -1, y);
	if (check_coords(map, x + 1, y))
		tmp_path(map, x + 1, y);
	if (check_coords(map, x, y - 1))
		tmp_path(map, x, y - 1);
	if (check_coords(map, x, y + 1))
		tmp_path(map, x, y + 1);
}

void	check_collectibles(void)
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
			if (game()->map.tmp[y][x] == 'C')
				error_message("No path to all collectibles");
			x++;
		}
		y++;
	}
}

void	check_exit(void)
{
	if (game()->map.tmp[game()->exity - 1][game()->exitx] == 'P' || \
		game()->map.tmp[game()->exity + 1][game()->exitx] == 'P' || \
		game()->map.tmp[game()->exity][game()->exitx - 1] == 'P' || \
		game()->map.tmp[game()->exity][game()->exitx + 1] == 'P')
		return ;
	else
		error_message("No path to the exit");
}

void	map_path(void)
{
	tmp_path(&game()->map, game()->posx, game()->posy);
	check_collectibles();
	check_exit();
}

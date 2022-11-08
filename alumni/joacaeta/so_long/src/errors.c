/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 19:14:39 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/22 23:51:41 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	rectangular(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strlen(map->map[i]) != ft_strlen(map->map[0]))
			error_message("Map not rectangular");
		i++;
	}
	map->width = (ft_strlen(map->map[0]) - 1);
}

void	surrounded(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < map->height)
	{
		while (map->map[j][i] != '\n' && map->map[j][i])
		{
			if (map->map[j][i] != '1')
				error_message("Map not surrounded (top/bottom)");
			i++;
		}
		j += (map->height - 1);
	}
	j = 0;
	while (j < (map->height))
	{
		if (map->map[j][0] != '1' || map->map[j][map->width - 1] != '1')
			error_message("Map not surrounded (sides)");
		j++;
	}
}

void	map_errors(void)
{
	rectangular(&game()->map);
	surrounded(&game()->map);
	elements();
	map_path();
}

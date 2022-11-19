/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:52:47 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/23 04:15:16 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//calculates the height of the map
int	get_height(char *mapfile)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(mapfile, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	close(fd);
	return (height);
}

//gets the map from the .ber file
t_map	get_map(char *mapfile)
{
	int		fd;
	int		i;
	char	*line;
	t_map	map;

	map.file = mapfile;
	map.height = get_height(mapfile);
	fd = open(mapfile, O_RDONLY);
	map.map = (char **)malloc(sizeof(char *) * (map.height + 1));
	map.tmp = (char **)malloc(sizeof(char *) * (map.height + 1));
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map.map[i] = line;
		map.tmp[i++] = ft_strdup(line);
		line = get_next_line(fd);
	}
	map.map[i] = "\0";
	map.tmp[i] = "\0";
	close(fd);
	return (map);
}

//prints a map to the terminal (for testing)
void	print_map(char **map)
{
	int	i;

	i = 0;
	while (i < game()->map.height)
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
}

//renders the full map
void	render_map(void)
{
	int		x;
	int		y;
	char	type;

	y = 0;
	while (y < game()->map.height)
	{
		x = 0;
		while (x < game()->map.width)
		{
			type = game()->map.map[y][x];
			render_image(x, y, type);
			x++;
		}
		y++;
	}
	render_image(x, y, type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:20:08 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/12 22:02:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

/*
determines & returns the total number of lines of the map_file. starts with
value '1', as we already read the first line to determine map.width.
*/
int	ft_mapheight(int fd, t_map map)
{
	map.height = 1;
	while (get_next_line(fd))
			++map.height;
	return (map.height);
}

/*
allocates memory for a matrix, using the previously determined
maps' height and stores a duplicate of map's contents in it.
*/
char	**ft_savemap(int fd, t_map map)
{
	int		i;

	i = 0;
	map.matrix = malloc (sizeof map.matrix * map.height + 1);
	if (!map.matrix)
		return (NULL);
	while (i < map.height)
	{
		map.matrix[i] = ft_strdup(get_next_line(fd));
		if (!map.matrix)
			return (NULL);
		++i;
	}
	map.matrix[map.height] = NULL;
	return (map.matrix);
}


// saves the posistion (x,y) of the gameObject passed as a parameter
t_gameObject	ft_setposition(t_map map, t_gameObject chrctr, int c, int nbr)
{
	int	x;
	int	y;
	int	i;
	int	characters;

	i = -1;
	y = -1;
	characters = -1;
	while (++characters < nbr)
	{
		while (++y < map.height - 1)
		{
			x = -1;
			while (++x < map.width - 1)
			{
				if (map.matrix[y][x] == c)
				{
					chrctr.x_pos[++i] = x;
					chrctr.y_pos[i] = y;
				}
			}
		}
	}
	return (chrctr);
}

// saves the posistions (x,y) of every gameObject present in the file_map
t_characters	ft_charactersposition(t_map map, t_characters chars)
{
	int				i;

	chars.player = ft_setposition(map, chars.player, 'P', 1);
	chars.exit = ft_setposition(map, chars.exit, 'E', 1);
	chars.collect = ft_setposition(map, chars.collect, 'C', map.collectibles);
	return (chars);
}

/*
"maps out" 't_map map', by assigning map_file's values to its corresponding 
element in the t_map struct; this includes keeping a record of each character's 
position, as well as, a copy of the map itself.
*/
t_map	ft_mapping(char **argv)
{
	int				fd;
	t_map			map;
	t_characters	characters;

	fd = open(argv[1], O_RDONLY);
	map.width = (int)ft_strlen_sl(get_next_line(fd));
	if (map.width < 3)
		return (map);
	map.height = ft_mapheight(fd, map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map.matrix = ft_savemap(fd, map);
	close(fd);
	return (map);
}

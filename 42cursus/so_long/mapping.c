/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:20:08 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/12 01:08:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

// a variation of ft_strlen, to exlude the '\n' character
int	ft_strlen_sl(char *string)
{
	int	len;

	len = 0;
	while (string[len] && string[len] != '\n')
		++len;
	return (len);
}

// determines & returns the total number of lines of the map_file 
int	ft_mapheight(int fd, t_map map)
{
	map.height = 0;
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
	int	i;

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

/*
"maps out" 't_map map', by assigning map_file's values to its corresponding 
element in the t_map struct; this includes making a copy of the map itself.
*/
t_map	ft_mapping(char **argv)
{
	int		fd;
	t_map	map;

	map.map_file = argv[1];
	fd = open(argv[1], O_RDONLY);
	map.height = ft_mapheight(fd, map);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map.width = (int)ft_strlen_sl(get_next_line(fd));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map.matrix = ft_savemap(fd, map);
	close(fd);
	return (map);
}

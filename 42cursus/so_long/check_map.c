/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 19:29:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/12 01:00:15 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
checks if the provided map has exactly 1 'player' character, exactly 1 'exit'
character and at least one 'collectible' character
*/
int	ft_checkelements(t_map map)
{
	int	i;
	int	line;
	int	exit;
	int	player;
	int	collectibles;

	line = -1;
	exit = 0;
	player = 0;
	collectibles = 0;
	while (++line < map.height)
	{
		i = -1;
		while (map.matrix[line][++i])
		{
			if (map.matrix[line][i] == 'P')
				++player;
			if (map.matrix[line][i] == 'E')
				++exit;
			if (map.matrix[line][i] == 'C')
				++collectibles;
		}
	}
	if (player != 1 || exit != 1 || collectibles == 0)
		return (0);
	return (1);
}

// checks if the name of the file given as first argument ends with ".ber"
int	ft_checkextension(char *argv)
{
	char	*extension;
	int		ext_index;

	ext_index = ft_strlen(argv) - 4;
	extension = ".ber";
	if (ft_strncmp(extension, &argv[ext_index], 4) != 0)
		return (0);
	return (1);
}

/*
checks if '1' is the first & last character of every line of the map, as well
as, if '1' is also the only character in the first & last lines of the map.
*/
int	ft_checkborders(t_map map)
{
	int	i;

	i = 1;
	while (i < map.height)
	{
		if (ft_strlen_sl(map.matrix[i]) != map.width)
			return (0);
		if (map.matrix[i][0] != '1' || map.matrix[i][map.width - 1] != '1')
			return (0);
		++i;
	}
	i = -1;
	while (++i < map.width)
	{
		if (map.matrix[0][i] != '1')
			return (0);
	}
	i = -1;
	while (++i < map.width)
	{
		if (map.matrix[map.height - 1][i] != '1')
			return (0);
	}
	return (1);
}

/*
checks if there is a valid path for the 'player' character to reach the 'exit'
character, after sucessfully reaching all 'collectible' characters.
*/
int	ft_checkpath(t_map map)
{
	return (1);
}

/*
calls 4 sub-functions to check if the file given as an argument is a valid
map; exits after returning a different error message for each failed check.
*/
int	ft_checkmap(char **argv)
{
	t_map	map;

	if (!ft_checkextension(argv[1]))
	{
		write(1, "Error\nInvalid map_file extension.\n", 34);
		return (0);
	}
	map = ft_mapping(argv);
	if (!ft_checkborders(map))
	{
		write(1, "Error\nInvald map structure.\n", 28);
		return (0);
	}
	if (!ft_checkelements(map))
	{
		write(1, "Error\nInvalid number of characters.\n", 36);
		return (0);
	}
	if (!ft_checkpath(map))
	{
		write(1, "Error\nNo valid path found.\n", 27);
		return (0);
	}
	free(map.matrix);
	return (1);
}

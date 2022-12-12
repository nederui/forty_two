/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:56:45 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/12 00:55:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
the program starts with two checks: if it was only given one argument and,
if so, if the map_file (the file provided as an argument) is a valid map.
*/
int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "Error\ntoo many arguments.", 25);
		return (0);
	}
	if (ft_checkmap(argv))
		write(1, "map: OK!\n", 9);
	return (0);
}

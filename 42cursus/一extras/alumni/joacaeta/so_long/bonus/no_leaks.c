/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_leaks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:07:57 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/27 02:24:16 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	no_leaks_map(void)
{
	int	i;

	i = 0;
	while (i < get_height(game()->map.file))
	{
		if (game()->map.map[i])
			free(game()->map.map[i]);
		if (game()->map.tmp[i])
			free(game()->map.tmp[i]);
		i++;
	}
	if (game()->map.map)
		free(game()->map.map);
	if (game()->map.tmp)
		free(game()->map.tmp);
}

void	no_leaks(void)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (game()->sprites.imgs[i])
			mlx_destroy_image(game()->mlx, game()->sprites.imgs[i]);
		i++;
	}
	no_leaks_map();
	mlx_destroy_window(game()->mlx, game()->win);
	mlx_destroy_display(game()->mlx);
	free(game()->mlx);
}

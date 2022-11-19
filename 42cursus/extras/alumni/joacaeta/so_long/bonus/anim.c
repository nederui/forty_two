/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 03:05:59 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/23 03:24:40 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	animloop2(int x, int y)
{
	static int		i;
	static int		j;

	if (game()->map.map[y][x] == 'C')
	{
		i = rand() % 6;
		mlx_put_image_to_window(game()->mlx, \
		game()->win, game()->sprites.imgs[COL + i], x * 32, y * 32);
	}
	if (game()->map.map[y][x] == 'F')
	{
		j = rand() % 8;
		j++;
		mlx_put_image_to_window(game()->mlx, \
		game()->win, game()->sprites.imgs[ENEMY + j], x * 32, y * 32);
	}
}

//animation loop (collectibles, and enemies)
int	animloop(void)
{
	int				x;
	int				y;
	static int		time;

	y = 0;
	if (time++ < 50000)
		return (1);
	time = 0;
	while (y < game()->map.height)
	{
		x = 0;
		while (x < game()->map.width)
		{
			animloop2(x, y);
			x++;
		}
		y++;
	}
	return (0);
}

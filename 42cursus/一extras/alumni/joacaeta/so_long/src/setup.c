/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:59:51 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/23 04:20:32 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//creates the window of the game
void	create_window(void)
{
	(game())->win = mlx_new_window(game()->mlx, (game()->map.width * 32), \
		(game()->map.height * 32), "so_long");
}

//loads image elements (collectibles) of the game to a void pointer
void	load_collectible(void)
{
	static char	file[24] = "images/collectible1.xpm";
	int			i;

	i = 1;
	while (i < 7)
	{
		file[18] = (i + '0');
		(game())->sprites.imgs[COL + i - 1] = \
		mlx_xpm_file_to_image(game()->mlx, file, &game()->sprites.width, \
		&game()->sprites.height);
		i++;
	}
}

//loads image elements (enemys) of the game to a void pointer
void	load_enemy(void)
{
	static char	file[18] = "images/enemy1.xpm";
	int			i;

	i = 1;
	while (i < 10)
	{
		file[12] = (i + '0');
		(game())->sprites.imgs[ENEMY + i - 1] = \
		mlx_xpm_file_to_image(game()->mlx, file, &game()->sprites.width, \
		&game()->sprites.height);
		i++;
	}
}

//loads image elements (sprites and textures) of the game to a void pointer
void	get_sprites(void)
{
	load_collectible();
	load_enemy();
	(game())->sprites.imgs[PLAYER] = mlx_xpm_file_to_image(game()->mlx, \
	"images/player_start.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[EXIT_CLOSE] = mlx_xpm_file_to_image(game()->mlx, \
	"images/door_close.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[EXIT_OPEN] = mlx_xpm_file_to_image(game()->mlx, \
	"images/door_open.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[EMPTY] = mlx_xpm_file_to_image(game()->mlx, \
	"images/ground.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[WALL] = mlx_xpm_file_to_image(game()->mlx, \
	"images/wall.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[WIN] = mlx_xpm_file_to_image(game()->mlx, \
	"images/win.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[LOSE] = mlx_xpm_file_to_image(game()->mlx, \
	"images/lose.xpm", &game()->sprites.width, &game()->sprites.height);
}

//loads image elements (numbers) of the game to a void pointer
void	get_numbers(void)
{
	(game())->sprites.imgs[NUMBERS + 0] = mlx_xpm_file_to_image(game()->mlx, \
	"images/0.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 1] = mlx_xpm_file_to_image(game()->mlx, \
	"images/1.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 2] = mlx_xpm_file_to_image(game()->mlx, \
	"images/2.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 3] = mlx_xpm_file_to_image(game()->mlx, \
	"images/3.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 4] = mlx_xpm_file_to_image(game()->mlx, \
	"images/4.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 5] = mlx_xpm_file_to_image(game()->mlx, \
	"images/5.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 6] = mlx_xpm_file_to_image(game()->mlx, \
	"images/6.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 7] = mlx_xpm_file_to_image(game()->mlx, \
	"images/7.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 8] = mlx_xpm_file_to_image(game()->mlx, \
	"images/8.xpm", &game()->sprites.width, &game()->sprites.height);
	(game())->sprites.imgs[NUMBERS + 9] = mlx_xpm_file_to_image(game()->mlx, \
	"images/9.xpm", &game()->sprites.width, &game()->sprites.height);
}

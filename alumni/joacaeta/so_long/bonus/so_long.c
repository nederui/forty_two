/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:23:11 by joacaeta          #+#    #+#             */
/*   Updated: 2022/11/06 21:25:22 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//renders an image on the window
void	render_image(int x, int y, char type)
{
	void	*sprite;

	sprite = NULL;
	if (type == 'P')
		sprite = game()->sprites.imgs[PLAYER];
	if (type == 'E')
	{
		if (game()->elems.col == 0)
			sprite = game()->sprites.imgs[EXIT_OPEN];
		else
			sprite = game()->sprites.imgs[EXIT_CLOSE];
	}
	if (type == '0')
		sprite = game()->sprites.imgs[EMPTY];
	if (type == '1')
		sprite = game()->sprites.imgs[WALL];
	if (type == 'C')
		sprite = game()->sprites.imgs[COL];
	if (type == 'W')
		sprite = game()->sprites.imgs[WIN];
	if (type == 'F')
		sprite = game()->sprites.imgs[ENEMY];
	if (sprite != NULL)
		mlx_put_image_to_window(game()->mlx, \
		game()->win, sprite, x * 32, y * 32);
}

//destroys the window and the whole game
int	destroy(void *param)
{
	(void)param;
	no_leaks();
	exit(0);
	return (0);
}

//handles the key press event
int	key_press(int kcd, t_game *g)
{
	(void)g;
	if (kcd == ESC)
		destroy(g);
	if (!game()->finish)
	{
		if (kcd == W || kcd == UP_A || kcd == A || kcd == LEFT_A \
				|| kcd == S || kcd == DOWN_A || kcd == D || \
				kcd == RIGHT_A)
			move(kcd);
		if (game()->elems.col == 0)
			render_image(game()->exitx, game()->exity, 'E');
	}
	return (0);
}

//returns the game struct, which contains everything you need
t_game	*game(void)
{
	static t_game	game;

	return (&game);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Wrong Number of args", 1);
		ft_putstr_fd("\n", 1);
		exit(0);
	}
	game()->map = get_map(argv[1]);
	map_errors();
	game()->mlx = mlx_init();
	create_window();
	get_sprites();
	get_numbers();
	render_map();
	mlx_key_hook(game()->win, key_press, game());
	mlx_hook(game()->win, 17, (1L << 17), destroy, game());
	mlx_loop_hook(game()->mlx, animloop, NULL);
	mlx_loop(game()->mlx);
	return (0);
}

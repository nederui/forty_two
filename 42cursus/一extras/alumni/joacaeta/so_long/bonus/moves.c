/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 23:56:42 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/23 04:04:34 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

//renders the number of moves to the screen
int	render_number(int n, int x, int y)
{
	if (n >= 10)
		x = (render_number((n / 10), x, y));
	mlx_put_image_to_window(game()->mlx, game()->win, \
	game()->sprites.imgs[NUMBERS + (n % 10)], x * 32, y);
	return (x + 1);
}

//renders the move to the screen, if process_move allowed it
void	render_move(int xi, int yi, char whereis)
{
	render_image(game()->posx + xi, game()->posy + yi, whereis);
	game()->map.map[game()->posy + yi][game()->posx + xi] = whereis;
	render_image(game()->posx, game()->posy, '0');
	game()->map.map[game()->posy][game()->posx] = '0';
	game()->posx = game()->posx + xi;
	game()->posy = game()->posy + yi;
	if (whereis == 'E')
	{
		render_image(game()->map.width / 2 - 1, 0, 'W');
		game()->nmoves++;
		render_number(game()->nmoves, 0, (game()->map.height -1) * 32);
	}
}

int	check_pos(int xi, int yi, char type)
{
	return (game()->map.map[game()->posy + yi][game()->posx + xi] == type);
}

//processes the move (either allowing it to happen or not)
void	process_move(int xi, int yi)
{
	char	whereis;

	whereis = 'P';
	if (check_pos(xi, yi, 'C'))
		game()->elems.col--;
	if (!check_pos(xi, yi, 'E'))
		whereis = 'P';
	else
	{
		if (game()->elems.col == 0)
		{
			whereis = 'E';
			game()->finish = 1;
		}
	}
	if (check_pos(xi, yi, 'F'))
	{
		mlx_put_image_to_window(game()->mlx, game()->win, \
		game()->sprites.imgs[LOSE], (game()->map.width / 2 - 1) * 32, 0);
		whereis = 'F';
		game()->finish = 1;
	}
	if ((!check_pos(xi, yi, 'E')) || (check_pos(xi, yi, 'E') \
		&& game()->elems.col == 0))
		render_move(xi, yi, whereis);
}

//decides the move according to which key was pressed
void	move(int kcd)
{
	int	xi;
	int	yi;

	xi = 0;
	yi = 0;
	if (kcd == W || kcd == UP_A)
		yi = -1;
	if (kcd == A || kcd == LEFT_A)
		xi = -1;
	if (kcd == S || kcd == DOWN_A)
		yi = 1;
	if (kcd == D || kcd == RIGHT_A)
		xi = 1;
	if (game()->map.map[game()->posy + yi][game()->posx + xi] == 'C' || \
		game()->map.map[game()->posy + yi][game()->posx + xi] == '0' || \
		game()->map.map[game()->posy + yi][game()->posx + xi] == 'E' || \
		game()->map.map[game()->posy + yi][game()->posx + xi] == 'F')
	{
		if (game()->map.map[game()->posy + yi][game()->posx + xi] != 'E')
		{
			game()->nmoves++;
			render_number(game()->nmoves, 0, (game()->map.height -1) * 32);
		}
		process_move(xi, yi);
	}
}

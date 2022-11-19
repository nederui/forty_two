/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:17:35 by joacaeta          #+#    #+#             */
/*   Updated: 2022/11/06 21:51:37 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/get_next_line_bonus.h"
# include <stdlib.h>

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP_A 65362
# define LEFT_A 65361
# define DOWN_A 65364
# define RIGHT_A 65363

# define PLAYER 0
# define EXIT_CLOSE 1
# define EXIT_OPEN 2
# define EMPTY 3
# define WALL 4
# define WIN 5
# define LOSE 6
# define COL 7
# define ENEMY 13
# define NUMBERS 22

typedef struct s_elems
{
	int	exit;
	int	pos;
	int	col;
	int	wall;
	int	empty;
	int	enemy;
}	t_elems;

typedef struct s_map
{
	int		height;
	int		width;
	char	*file;
	char	**map;
	char	**tmp;
}	t_map;

typedef struct s_sprites
{
	int		width;
	int		height;
	void	*imgs[32];
}	t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			posx;
	int			posy;
	int			exitx;
	int			exity;
	int			nmoves;
	int			finish;
	t_map		map;
	t_elems		elems;
	t_sprites	sprites;
}	t_game;

//errors
void		error_message(char	*message);
void		rectangular(t_map *map);
void		surrounded_tb(int i, int j, t_map *map);
void		surrounded_sides(int j, t_map *map);
void		surrounded(t_map *map);
int			check_coords(t_map *map, int x, int y);
void		tmp_path(t_map *map, int x, int y);
void		check_collectibles(void);
void		check_exit(void);
void		map_path(void);
void		check_elem(int x, int y);
int			elem_limits(void);
void		elements(void);
void		map_errors(void);

//map
int			get_height(char *mapfile);
t_map		get_map(char *mapfile);
void		print_map(char **map);
void		render_map(void);

//setup
void		create_window(void);
void		get_sprites(void);
void		get_numbers(void);

//moves
void		print_moves(void);
void		render_move(int xi, int yi, char whereis);
void		process_move(int xi, int yi);
void		move(int kcd);

//anim
int			animloop(void);
void		animloop2(int x, int y);

//leaks
void		no_leaks(void);
void		no_leaks_map(void);

//main
void		render_image(int x, int y, char type);
int			key_press(int keycode, t_game *g);
int			destroy(void *param);
t_game		*game(void);

#endif

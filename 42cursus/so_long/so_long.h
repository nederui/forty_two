/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:58:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/12 23:46:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
// LIBRARIES

# include "includes/ft_printf.h"
# include "includes/libft.h"
# include "includes/get_next_line.h"

/* ************************************************************************** */
// STRUCTURES

typedef struct s_map
{
	int		width;
	int		height;
	char	**matrix;

	int		collectibles;	// unecessary?
	int		exit;			// unecessary?
	int		player;			// unecessary?
}	t_map;

typedef struct s_sprite
{
	int		width;
	int		height;
	void	*img_file[32];
}	t_sprite;

typedef struct s_gameObject
{
	t_sprite	sprite;
	int			x_pos[100];
	int			y_pos[100];
	char		*animation[240];
	int			collision;
}	t_gameObject;

typedef struct s_characters
{
	t_gameObject	player;
	t_gameObject	exit;
	t_gameObject	collect;
}	t_characters;

// typedef struct s_ft_
// {
// 	int	ft_iszero_is_c(int c);
// }	t_ft_;

/* ************************************************************************** */
// MAP HANDLING

t_map			ft_mapping(char **argv);
int				ft_mapheight(int fd, t_map map);
char			**ft_savemap(int fd, t_map map);
int				ft_strlen_sl(char *string);

int				ft_checkmap(char **argv);
int				ft_checkextension(char *argv);
int				ft_checkborders(t_map map);
int				ft_checkelements(t_map map);
t_characters	ft_charactersposition(t_map map, t_characters chars);
t_gameObject	ft_setposition(t_map map, t_gameObject chrctr, int c, int nbr);
int				ft_checkpath(t_map map);
int				ft_pathing(t_map map, t_gameObject character);

#endif
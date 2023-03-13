/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:10:17 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/13 00:44:40 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_debug_path(void)
{
	ft_printf("DEBUG_START\n\n");
	while (*pipex()->paths)
	{
		ft_printf("%s\n", *pipex()->paths);
		*pipex()->paths++;
	}
	ft_printf("\nDEBUG_END\n");
}

/*
a variation of ft_strjoin(), which makes use of ft_strlen_gnl() to concatenate
'buffer' to 'line' only up to either the '\0' or the '\n' characters; it returns
the new 'line' and makes sure the previous form of 'line' is free'd;
*/
char	*ft_strjoin_pipex(char *original_path, char *cmd)
{
	char	*new_path;
	int		i;
	int		i_c;
	int		len_og;
	int		len_cmd;

	if (!cmd || !original_path)
		return (NULL);
	len_og = ft_strlen(original_path);
	len_cmd = ft_strlen(cmd);
	new_path = malloc(sizeof new_path * len_og + len_cmd + 1 + 1);
	if (!new_path)
		return (NULL);
	i = -1;
	i_c = i;
	while (++i < len_og)
		new_path[i] = original_path[i];
	new_path[i++] = '/';
	while (++i_c < len_cmd)
		new_path[i + i_c] = cmd[i_c];
	new_path[i + i_c] = 0;
	free(original_path);
	return (new_path);
}

// char	*ft_strjoin_pipex(char *original_path, char *dash)
// {
// 	char	*new_path;
// 	int		i;
// 	int		len;

// 	if (!original_path)
// 		return (NULL);
// 	len = ft_strlen(original_path);
// 	new_path = malloc(sizeof new_path * len + 1 + 1);
// 	if (!new_path)
// 		return (NULL);
// 	i = -1;
// 	while (++i < len)
// 		new_path[i] = original_path[i];
// 	new_path[i++] = '/';
// 	new_path[i] = 0;
// 	free(original_path);
// 	return (new_path);
// }

/*
this group of functions keep all the data of its corresponding structure static
during the runtime of the program; it allows the access of these structs' data
to all the functions that need to read from / modify them, by a simple call of:
example_struct(), as they return the address of the struct they are assigned to
*/

t_pipex	*pipex(void)
{
	static t_pipex	pipex;

	return (&pipex);
}

/*
displays a custom error message and runs ft_exit() for a clean program exit;
returns 0 to exit 'check_map.c' functions in the event of an error being found
*/
int	ft_error(char *message)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	// ft_exit();
	return (0);
}

// frees the data previously allocated for the copy of the map
// void	ft_freewillie(void)
// {
// 	int	y;

// 	y = 0;
// 	while (map()->matrix[y])
// 	{
// 		free(map()->matrix[y]);
// 		++y;
// 	}
// 	free(map()->matrix);
// 	map()->matrix = NULL;
// }

// ensures a clean program exit (including closing the map_file fd)
// void	ft_exit(void)
// {
// 	if (img()->img)
// 		mlx_destroy_image(game()->mlx, img()->img);
// 	if (game()->win)
// 		mlx_destroy_window(game()->mlx, game()->win);
// 	if (game()->mlx)
// 	{
// 		mlx_destroy_display(game()->mlx);
// 		free(game()->mlx);
// 	}
// 	if (map()->matrix)
// 		ft_freewillie();
// 	// if() checking if the player reached the exit (?)
// 	if (game()->highscore)
// 		ft_check_final_score();
// 	exit(0);
// }

// places one string in between another string, at the given index
// char	*ft_strsandwich(char *ham, char *bread, int index)
// {
// 	char	*sandwich;
// 	size_t	ham_len;
// 	size_t	bread_len;

// 	ham_len = ft_strlen(ham);
// 	bread_len = ft_strlen(bread);
// 	sandwich = malloc(ham_len + bread_len + 1);
// 	if (!sandwich)
// 		return (NULL);
// 	sandwich[ham_len + bread_len] = '\0';
// 	ft_memcpy(sandwich, bread, index);
// 	ft_memcpy(sandwich + index, ham, ham_len);
// 	ft_memcpy(sandwich + index + ham_len, bread + index, bread_len - index);
// 	return (sandwich);
// }

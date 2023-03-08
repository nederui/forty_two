/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:10:17 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/08 00:15:49 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

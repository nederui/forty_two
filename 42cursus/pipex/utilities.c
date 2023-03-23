/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:10:17 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/23 02:01:03 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
a variation of ft_strjoin(), which makes use of ft_strlen_gnl() to concatenate
'buffer' to 'line' only up to either the '\0' or the '\n' characters; it returns
the new 'line' and makes sure the previous form of 'line' is free'd;
*/
char	*ft_strjoin_ppx(char *original_path, char *cmd)
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
	char	*uno;
	char	*dos;

	uno = "1";
	dos = "2";
	ft_putstr_fd("Error\n", 1);
	if (!ft_strncmp(message, uno, 1) || !ft_strncmp(message, dos, 1))
	{
		if (!pipex()->valid_path[0])
			ft_printf("%s: Command not found.\n", pipex()->cmd_one[0]);
		if (!pipex()->valid_path[1] || !ft_strncmp(message, dos, 1))
			ft_printf("%s: Command not found.\n", pipex()->cmd_two[0]);
	}
	else
	{
		ft_putstr_fd(message, 1);
		ft_putchar_fd('\n', 1);
	}
	ft_exit();
	return (0);
}

// frees the data previously allocated for the copy of the map
void	ft_freewillie(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
	array = NULL;
}

// ensures a clean program exit (including closing the map_file fd)
void	ft_exit(void)
{
	if (pipex()->cmd_one)
		ft_freewillie(pipex()->cmd_one);
	if (pipex()->cmd_two)
		ft_freewillie(pipex()->cmd_two);
	if (pipex()->paths)
		ft_freewillie(pipex()->paths);
	if (pipex()->paths2)
		ft_freewillie(pipex()->paths2);
	free(pipex()->valid_path[0]);
	free(pipex()->valid_path[1]);
	exit(0);
}

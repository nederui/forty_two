/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:10:17 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/19 19:09:27 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
a variation of ft_strjoin(), which concatenates '/' and the given command to
given path; returns a 'new path' to be subsequentely validated and makes sure
the original path (obtained through the 'envp' matrix) is free'd
*/
char	*strjoin_ppx(char *original_path, char *cmd)
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
	new_path = ft_calloc(sizeof(char), len_og + len_cmd + 1 + 1);
	if (!new_path)
		return (NULL);
	i = -1;
	i_c = i;
	while (++i < len_og)
		new_path[i] = original_path[i];
	new_path[i++] = '/';
	while (++i_c < len_cmd)
		new_path[i + i_c] = cmd[i_c];
	free(original_path);
	return (new_path);
}

/*
this function keep all the data of its corresponding structure static during 
the runtime of the program; it allows the access of this structs' data to
all the functions that need to read from / modify them, by a simple call of
"pipex()", as it returns the address of the struct it is assigned to (t_pipex)
*/
t_pipex	*pipex(void)
{
	static t_pipex	pipex;

	return (&pipex);
}

/*
displays a custom error message and runs exit_() for a clean program exit;
returns 0 to exit any function in the event of an error being found
*/
int	error_(char *message)
{
	char	*inv_one;
	char	*inv_two;

	inv_one = "invalid_cmd_one";
	inv_two = "invalid_cmd_two";
	ft_putstr_fd("Error\n", 2);
	if (!ft_strncmp(message, inv_one, 1) || !ft_strncmp(message, inv_two, 1))
	{
		if (!pipex()->valid_path[0])
			ft_printf("%s: Command not found.\n", pipex()->cmd_one[0]);
		if (!pipex()->valid_path[1])
			ft_printf("%s: Command not found.\n", pipex()->cmd_two[0]);
	}
	else
	{
		ft_putstr_fd(message, 2);
		ft_putchar_fd('\n', 2);
	}
	exit_();
	return (FAILURE);
}

// frees the data previously allocated for any of the program's matrix
void	freewillie(char **array)
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

// ensures a clean program exit (including closing any open fd)
void	exit_(void)
{
	if (pipex()->cmd_one)
		freewillie(pipex()->cmd_one);
	if (pipex()->cmd_two)
		freewillie(pipex()->cmd_two);
	if (pipex()->paths)
		freewillie(pipex()->paths);
	if (pipex()->paths2)
		freewillie(pipex()->paths2);
	free(pipex()->valid_path[0]);
	free(pipex()->valid_path[1]);
	exit(0);
}

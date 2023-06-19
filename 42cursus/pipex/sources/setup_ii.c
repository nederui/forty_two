/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:18:05 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/19 19:18:21 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

/*
goes through the list of possible paths to find the first valid path to each
command passed as argument, saving each one on success
*/
int	validate_paths(char **paths, char **valid_path)
{
	int	i;

	i = 0;
	while (paths[i] != 0)
	{
		if (!access(paths[i], F_OK))
		{
			*valid_path = ft_strdup(paths[i]);
			if (!valid_path)
				return (error_("Memory allocation error, \
whilst saving the correct path for the first command."));
			break ;
		}
		i++;
	}
	return (SUCCESS);
}

/*
makes use of the modified version of 'ft_strjoin' to attach each command
passed as argument to every possible 'envp' path
*/
int	append_cmds(char **paths, char **command)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		(paths[i]) = strjoin_ppx(paths[i], command[0]);
		if (!paths[i])
			return (error_("Memory allocation error, \
whilst loading the envp paths."));
		i++;
	}
	return (SUCCESS);
}

/*
checks if a valid path to the given command has already been found;
if not, it appends the given commands to each 'envp' path and validates it;
returns the current value of 'status', which will be '1' or '0', depending on
wether or not it finds a valid path for both of the given commands
*/
int	check_append_validate(void)
{
	int	status;

	status = SUCCESS;
	if (!pipex()->valid_path[0] && pipex()->cmd_one[0])
		if (!append_cmds(pipex()->paths, pipex()->cmd_one) || \
		!validate_paths(pipex()->paths, &pipex()->valid_path[0]))
			status = FAILURE;
	if (!pipex()->valid_path[1] && pipex()->cmd_two[0])
		if (!append_cmds(pipex()->paths2, pipex()->cmd_two) || \
		!validate_paths(pipex()->paths2, &pipex()->valid_path[1]))
			status = FAILURE;
	return (status);
}

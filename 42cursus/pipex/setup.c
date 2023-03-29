/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/29 01:21:21 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	ft_check_args(void)
{
	if (!access(pipex()->cmd_one[0], F_OK))
		pipex()->valid_path[0] = pipex()->cmd_one[0];
	else if (!ft_append_cmds(pipex()->paths, pipex()->cmd_one))
		return (FAILURE);
	if (!access(pipex()->cmd_two[0], F_OK))
		pipex()->valid_path[1] = pipex()->cmd_two[0];
	else if (!ft_append_cmds(pipex()->paths2, pipex()->cmd_two))
		return (FAILURE);
	return (SUCCESS);
}

// parses all paths found in the 'envp' matrix
int	ft_load_paths(char **envp)
{
	char	*path_string;

	path_string = "PATH=";
	while (*envp)
	{
		if (!ft_strncmp(*envp, path_string, 5))
		{
			(pipex()->paths) = ft_split(*envp + 5, ':');
			if (!pipex()->paths)
				return (ft_error("Memory allocation error, \
				whilst loading the envp paths."));
			(pipex()->paths2) = ft_split(*envp + 5, ':');
			if (!pipex()->paths2)
				return (ft_error("Memory allocation error, \
				whilst loading the envp paths."));
			return (SUCCESS);
		}
		envp++;
	}
	return (ft_error("Unable to find 'PATH=' in the environment pointer."));
}

// parses both commands passed as arguments
int	ft_load_cmds(char **argv)
{
	(pipex()->cmd_one) = ft_split(argv[2], ' ');
	(pipex()->cmd_two) = ft_split(argv[3], ' ');
	if (!pipex()->cmd_one || !pipex()->cmd_two)
		return (ft_error("Memory allocation error, \
		whilst saving the commands passed as arguments."));
	return (SUCCESS);
}

// opens both files passed as arguments (infile & outfile)
int	ft_access_files(char **argv)
{
	(pipex()->fd[0]) = open(argv[1], O_RDONLY);
	if (pipex()->fd[0] < 0)
		return (ft_error("Unable to open the infile."));
	(pipex()->fd[1]) = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex()->fd[1] < 0)
		return (ft_error("Unable to open/create the outfile file."));
	return (SUCCESS);
}

/*
validates each argument passed on launch, by parsing to the pipex() structure
through distinct functions;
returns '0' and a custom message when an error occurs and '1' on success
*/
int	ft_setup(char **argv, char **envp)
{
	if (!ft_access_files(argv) || !ft_load_cmds(argv) || \
							!ft_load_paths(envp) || !ft_check_args())
		return (FAILURE);
	if (!pipex()->valid_path[0])
		if (!ft_validate_paths(pipex()->paths, &pipex()->valid_path[0]))
			return (FAILURE);
	if (!pipex()->valid_path[1])
		if (!ft_validate_paths(pipex()->paths2, &pipex()->valid_path[1]))
			return (FAILURE);
	if (!pipex()->valid_path[0])
		return (ft_error("1"));
	if (!pipex()->valid_path[1])
		return (ft_error("2"));
	return (SUCCESS);
}

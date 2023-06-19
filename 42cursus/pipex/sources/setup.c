/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/19 18:22:27 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <fcntl.h>

//	checks if the given commands are already valid paths
int	check_args_access(void)
{
	if (pipex()->cmd_one[0] && !access(pipex()->cmd_one[0], F_OK))
	{
		pipex()->valid_path[0] = ft_strdup(pipex()->cmd_one[0]);
		if (!pipex()->valid_path[0])
			return (error_("Memory allocation error, \
whilst saving the valid path for the first command."));
	}
	if (pipex()->cmd_two[0] && !access(pipex()->cmd_two[0], F_OK))
	{
		pipex()->valid_path[1] = ft_strdup(pipex()->cmd_two[0]);
		if (!pipex()->valid_path[1])
			return (error_("Memory allocation error, \
whilst saving the valid path for the second command."));
	}
	return (SUCCESS);
}

// parses all paths found in the 'envp' matrix
int	load_paths(char **envp)
{
	char	*path_string;

	path_string = "PATH=";
	while (*envp)
	{
		if (!ft_strncmp(*envp, path_string, 5))
		{
			(pipex()->paths) = ft_split(*envp + 5, ':');
			if (!pipex()->paths)
				return (error_("Memory allocation error, \
whilst loading the envp paths."));
			(pipex()->paths2) = ft_split(*envp + 5, ':');
			if (!pipex()->paths2)
				return (error_("Memory allocation error, \
whilst loading the envp paths."));
			return (SUCCESS);
		}
		envp++;
	}
	return (error_("Unable to find 'PATH=' in the environment pointer."));
}

// parses both commands passed as arguments
int	load_cmds(char **argv)
{
	(pipex()->cmd_one) = ft_split(argv[2], ' ');
	(pipex()->cmd_two) = ft_split(argv[3], ' ');
	if (!pipex()->cmd_one || !pipex()->cmd_two)
		return (error_("Memory allocation error, \
whilst saving the commands passed as arguments."));
	return (SUCCESS);
}

// opens both files passed as arguments (infile & outfile)
int	access_files(char **argv)
{
	(pipex()->fd[0]) = open(argv[1], O_RDONLY);
	if (pipex()->fd[0] < 0)
		return (error_("Unable to open the infile."));
	(pipex()->fd[1]) = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex()->fd[1] < 0)
		return (error_("Unable to open/create the outfile file."));
	return (SUCCESS);
}

/*
validates each argument passed on launch, by parsing to the pipex() structure
through distinct functions;
returns '0' and a custom message when an error occurs and '1' on success
*/
int	setup(char **argv, char **envp)
{
	if (!access_files(argv) || !load_cmds(argv) || \
		!load_paths(envp) || !check_args_access() || !check_append_validate())
		return (FAILURE);
	return (SUCCESS);
}

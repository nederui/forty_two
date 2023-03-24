/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/24 17:02:24 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	ft_validate_paths(void)
{
	int	i;

	i = -1;
	while (pipex()->paths[++i] != 0)
	{
		if (!access(pipex()->paths[i], F_OK))
		{
			pipex()->valid_path[0] = ft_strdup(pipex()->paths[i]);
			if (!pipex()->valid_path[0])
				return (ft_error("Memory allocation error, \
		whilst saving the correct path for the first command."));
			break ;
		}
	}
	i = -1;
	while (pipex()->paths2[++i] != 0)
	{
		if (!access(pipex()->paths2[i], F_OK))
		{
			pipex()->valid_path[1] = ft_strdup(pipex()->paths2[i]);
			if (!pipex()->valid_path[1])
				return (ft_error("Memory allocation error, \
		whilst saving the correct path for the first command."));
			break ;
		}
	}
	return (1);
}

int	ft_append_cmds(void)
{
	int	i;

	i = 0;
	while (pipex()->paths[i])
	{
		(pipex()->paths[i]) = \
			ft_strjoin_ppx(pipex()->paths[i], pipex()->cmd_one[0]);
		if (!pipex()->paths[i])
			return (ft_error("Memory allocation error, \
		whilst loading the envp paths."));
		i++;
	}
	i = 0;
	while (pipex()->paths2[i])
	{
		(pipex()->paths2[i]) = \
			ft_strjoin_ppx(pipex()->paths2[i], pipex()->cmd_two[0]);
		if (!pipex()->paths2[i])
			return (ft_error("Memory allocation error, \
		whilst loading the envp paths."));
		i++;
	}
	return (1);
}

int	ft_load_paths(char **envp)
{
	char	*path_string;

	path_string = "PATH=";
	while (*envp)
	{
		if (!ft_strncmp(*envp, path_string, 5))
		{
			(pipex()->paths) = ft_split(*envp + 5, ':');
			(pipex()->paths2) = ft_split(*envp + 5, ':');
			if (!pipex()->paths || !pipex()->paths2)
				return (ft_error("Memory allocation error, \
			whilst loading the envp paths."));
			else
				return (1);
		}
		envp++;
	}
	return (ft_error("Unable to find 'PATH=' in the environment pointer."));
}

int	ft_load_cmds(char **argv)
{
	(pipex()->cmd_one) = ft_split(argv[2], ' ');
	(pipex()->cmd_two) = ft_split(argv[3], ' ');
	if (!pipex()->cmd_one || !pipex()->cmd_two)
		return (ft_error("Memory allocation error, \
			whilst saving the commands passed as arguments."));
	return (1);
}

int	ft_access_files(char **argv)
{
	(pipex()->fd[0]) = open(argv[1], O_RDONLY);
	if (pipex()->fd[0] < 0)
		return (ft_error("Unable to open the infile."));
	(pipex()->fd[1]) = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex()->fd[1] < 0)
		return (ft_error("Unable to open/create the outfile file."));
	return (1);
}

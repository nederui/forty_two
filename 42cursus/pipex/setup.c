/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/15 01:35:03 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>

int	ft_find_true_path(void)
{
	int	i;

	i = -1;
	while (pipex()->paths[++i] != 0)
	{
		if (!access(pipex()->paths[i], F_OK))
		{
			pipex()->true_path[0] = ft_strdup(pipex()->paths[i]);
			if (!pipex()->true_path[0])
				return (ft_error("Memory allocation error, \
		whilst saving the correct path for the first command."));
			ft_freewillie(pipex()->paths);
		}
	}
	i = -1;
	while (pipex()->paths2[++i] != 0)
	{
		if (!access(pipex()->paths2[i], F_OK))
		{
			pipex()->true_path[1] = ft_strdup(pipex()->paths2[i]);
			if (!pipex()->true_path[1])
				return (ft_error("Memory allocation error, \
		whilst saving the correct path for the first command."));
			ft_freewillie(pipex()->paths2);
		}
	}
	return (1);
}

int	ft_prep_paths(void)
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
	ft_freewillie(pipex()->cmd_one);
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
	ft_freewillie(pipex()->cmd_two);
	return (1);
}

int	ft_load_paths(char **argv, char **envp)
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
	// pipex()->files[0] = argv[1];
	// pipex()->files[1] = argv[4];
	(pipex()->fds[0]) = open(argv[1], O_RDONLY);
	(pipex()->fds[1]) = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex()->fds[0] < 0 || pipex()->fds[1] < 0)
		return (ft_error("Unable to open the file passed as argument."));
	return (1);
}

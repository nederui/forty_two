/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/12 23:50:15 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>

int	ft_prep_paths(void)
{
	int	i;

	i = 0;
	while (pipex()->paths[i])
	{
		(pipex()->paths[i]) = ft_strjoin_pipex(pipex()->paths[i], "ls");
		if (!pipex()->paths[i])
			return (ft_error("Memory allocation error, \
		whilst loading the envp paths."));
		i++;
	}
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
			if (!pipex()->paths)
				return (ft_error("Memory allocation error, \
			whilst loading the envp paths."));
			else
				return (1);
		}
		envp++;
	}
}

int	ft_loadcmds(char **argv)
{
	(pipex()->cmd_one) = ft_split(argv[2], ' ');
	(pipex()->cmd_two) = ft_split(argv[3], ' ');
	if (!pipex()->cmd_one || !pipex()->cmd_two)
		return (ft_error("Memory allocation error, \
			whilst saving the commands passed as arguments."));
	return (1);
}

int	ft_loadfiles(char **argv)
{
	pipex()->infile = argv[1];
	pipex()->outfile = argv[4];
	(pipex()->in_fd) = open(argv[1], O_RDONLY);
	(pipex()->out_fd) = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex()->in_fd < 0 || pipex()->out_fd < 0)
		return (ft_error("Unable to open the file passed as argument."));
	return (1);
}

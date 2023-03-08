/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:20:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/08 00:45:26 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <fcntl.h>
#include <stdio.h>

void	ft_save_paths(void)
{
	(pipex()->paths) = ft_split(pipex()->envp, ':');
	while (*pipex()->paths)
	{
		ft_printf("%s\n", *pipex()->paths);
		*pipex()->paths++;
	}
}

void	ft_load_env_paths(char *path, char **argv, char **envp)
{
	while (*envp)
	{
		if (!ft_strncmp(*envp, "PATH=", 5))
			pipex()->envp = *envp + 5;
		envp++;
	}
}

int	ft_loadcmds(char **argv)
{
	(pipex()->cmd_one) = ft_split(argv[2], ' ');
	(pipex()->cmd_two) = ft_split(argv[3], ' ');
	if (!pipex()->cmd_one || !pipex()->cmd_two)
		return (ft_error("Memory allocation error, \
			whilst loading the commands."));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:44:02 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/13 21:07:53 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"
#include <sys/wait.h>

// int	ft_attempt_exec(char **paths, char **argv, char **envp)
// {
// 	int	i;

// 	i = 0;
// 	while (pipex()->paths[i] != NULL)
// 	{
// 		ft_printf("HERE\n");
// 		execve(paths[i], argv, envp);
// 		i++;
// 	}
// }

int	supermario(void)
{
	pipe(pipex()->inlet);
	pipex()->id = fork();
	if (pipex()->id == 0)	//	child	//
	{
		close(pipex()->inlet[0]);
		// read from file1
		// find correct path for cmd1
		// execute cmd1 & save result
		close(pipex()->inlet[1]);
	}
	else					//	parent	//
	{
		close(pipex()->inlet[1]);
		// load result
		// find correct path for cmd2
		// execute cmd2 & save result
		// write final result to file2
		close(pipex()->inlet[0]);
		wait(NULL);
	}
	return (0);
}

int	ft_setup(char **argv, char **envp)
{
	if (!ft_loadfiles(argv) || !ft_loadcmds(argv) \
	|| !ft_load_paths(argv, envp) || !ft_prep_paths())
		return (0);
	ft_debug_setup();
	return (1);
}

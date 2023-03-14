/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:44:02 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/14 00:16:21 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"
#include <sys/wait.h>

// int	supermario(void)
// {
// 	if (pipe(pipex()->inlet) == -1)
// 		return (ft_error("Failed to create the pipe."));
// 	pipex()->id = fork();
// 	if (pipex()->id == -1)
// 		return (ft_error("Failed whilst trying to fork."));
// 	if (pipex()->id == 0)	//	child	//
// 	{
// 		close(pipex()->inlet[0]);
// 		// read from file1
// 		// find correct path for cmd1
// 		// execute cmd1 & save result
// 		close(pipex()->inlet[1]);
// 	}
// 	else					//	parent	//
// 	{
// 		close(pipex()->inlet[1]);
// 		// load result
// 		// find correct path for cmd2
// 		// execute cmd2 & save result
// 		// write final result to file2
// 		close(pipex()->inlet[0]);
// 		wait(NULL);
// 	}
// 	return (0);
// }

int	attempt_exec(char **paths, char **argv, char **envp)
{
	int	i;
	int	result;

	i = 0;
	while (paths[i])
	{
		result = execve(paths[i], argv, envp);
		i++;
	}
	if (result == -1)
		return (ft_error("Could not find the command passed as argument."));
	else
		return (1);
}

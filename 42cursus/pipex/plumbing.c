/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plumbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:44:02 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/17 03:19:53 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>
#include <sys/wait.h>

int	ft_secondchild(char **envp)
{
	close(pipex()->p1pe[1]);
	if (dup2(pipex()->p1pe[0], STDIN_FILENO) == -1)
		return (0);	//	WIP
	ft_printf("about to execve cmd2\n");
	if (dup2(pipex()->fd[1], STDOUT_FILENO) == -1)
		return (0);	//	WIP
	execve(pipex()->valid_path[1], pipex()->cmd_two, envp);
	ft_printf("second child is alive!\n");
	return (ft_error("Failed to execute the second command."));	//	WIP
}

int	ft_papi(char **envp)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		return (ft_error("Failed whilst trying to fork again."));
	if (id == 0)
		ft_secondchild(envp);
	else
	{
		// waitpid(id, NULL, 0);
		// wait(NULL);
	}
	return (0);
}

int	ft_firstborn(char **envp)
{
	close(pipex()->p1pe[0]);
	if (dup2(pipex()->fd[0], STDIN_FILENO) == -1)
		return (0);	//	WIP
	ft_printf("about to execve cmd1\n");
	if (dup2(pipex()->p1pe[1], STDOUT_FILENO) == -1)
		return (0);	//	WIP
	execve(pipex()->valid_path[0], pipex()->cmd_one, envp);
	return (ft_error("Failed to execute the first command."));	//	WIP
}

//  --->	read from [0]
//	--->	write on [1]
int	ft_plumbing(char **envp)
{
	pid_t	id;

	if (pipe(pipex()->p1pe) == -1)
		return (ft_error("Failed to create the first pipe."));
	id = fork();
	if (id == -1)
		return (ft_error("Failed whilst trying to fork."));
	if (id == 0)
		ft_firstborn(envp);
	else
	{
		wait(NULL);
		ft_papi(envp);
	}
	return (0);
}

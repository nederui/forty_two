/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plumbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:44:02 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/15 02:50:16 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"
#include <sys/wait.h>

int	ft_switcheroo(void)
{
	return (1);
}

int	ft_secondchild(char **envp)
{
	ft_switcheroo();
	execve(pipex()->valid_path[1], pipex()->cmd_two, envp);
	return (0);
}

int	ft_firstborn(char **envp)
{
	ft_switcheroo();
	execve(pipex()->valid_path[0], pipex()->cmd_one, envp);
	return (0);
}

int	ft_papi(char **envp)
{
	pid_t	id;

	if (pipe(pipex()->outlet) == -1)
		return (ft_error("Failed to create the second pipe."));
	id = fork();
	if (id == -1)
		return (ft_error("Failed whilst trying to fork again."));
	if (id == 0)
		ft_secondchild(envp);
	else
	{
		close(pipex()->inlet[0]);
		close(pipex()->outlet[1]);
		wait(NULL);
	}
	return (0);
}

//  --->	read from [0]
//	--->	write on [1]
int	ft_plumbing(char **envp)
{
	pid_t	id;

	if (pipe(pipex()->inlet) == -1)
		return (ft_error("Failed to create the first pipe."));
	id = fork();
	if (id == -1)
		return (ft_error("Failed whilst trying to fork."));
	if (id == 0)
		ft_firstborn(envp);
	else
	{
		close(pipex()->inlet[1]);
		close(pipex()->outlet[0]);
		wait(NULL);
		ft_papi(envp);
	}
	return (0);
}

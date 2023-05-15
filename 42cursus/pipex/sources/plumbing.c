/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plumbing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:44:02 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/04/25 15:51:23 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <unistd.h>
#include <sys/wait.h>

/*
the second 'child process' of our main process; it makes use of dup2()
to duplicate, substitute and close both SSTDIN_FILENO & STDOUT_FILENO, assigning
them to the outlet of our pipe (p1pe[1]) & our outfile (pipex()->fd[1]);
on success, it executes the second command passed as argument, thus ending
the second 'child process'
*/
int	leastfavorite(char **envp)
{
	if (dup2(pipex()->p1pe[0], STDIN_FILENO) == -1)
		return (error_("Failed to duplicate the pipe's fd (outfile)."));
	close(pipex()->p1pe[1]);
	close(pipex()->p1pe[0]);
	if (dup2(pipex()->fd[1], STDOUT_FILENO) == -1)
		return (error_("Failed to duplicate the outfile's fd."));
	close(pipex()->fd[0]);
	close(pipex()->fd[1]);
	execve(pipex()->valid_path[1], pipex()->cmd_two, envp);
	return (error_("execve() failed on the second command."));
}

int	papi(char **envp)
{
	pid_t	id;

	if(pipex()->valid_path[1])
	{
		id = fork();
		if (id == -1)
			return (error_("Failed whilst trying to fork again."));
		if (id == 0)
			leastfavorite(envp);
		close(pipex()->p1pe[0]);
		close(pipex()->p1pe[1]);
		waitpid(id, NULL, 0);
	}
	return (SUCCESS);
}

/*
the first 'child process' of our main process; it makes use of dup2()
to duplicate, substitute and close both SSTDIN_FILENO & STDOUT_FILENO, assigning
them to our infile (pipex()->fd[0]) & the inlet of our pipe (p1pe[1]);
on success, it executes the first command passed as argument, thus ending
the first 'child process'
*/
int	firstborn(char **envp)
{
	if (dup2(pipex()->fd[0], STDIN_FILENO) == -1)
		return (error_("Failed to duplicate the infile's fd."));
	close(pipex()->fd[1]);
	close(pipex()->fd[0]);
	if (dup2(pipex()->p1pe[1], STDOUT_FILENO) == -1)
		return (error_("Failed to duplicate the pipe's fd (infile)."));
	close(pipex()->p1pe[0]);
	close(pipex()->p1pe[1]);
	execve(pipex()->valid_path[0], pipex()->cmd_one, envp);
	return (error_("execve() failed on the first command."));
}

/*
the main function of pipex; creates the pipe that will be used to communicate
between processes, and runs fork() to create a second process; it waits for the
first 'child process' to finish, to fork() again and generate the third process;

to make each inlet of the pipe (pipex()->p1pe[2]) a one-way road, every process:
reads  from	[0]
writes on	[1]
*/
int	plumbing(char **envp)
{
	pid_t	id;

	if (pipe(pipex()->p1pe) == -1)
		return (error_("Failed to create the first pipe."));
	if(pipex()->valid_path[0])
	{
		id = fork();
		if (id == -1)
			return (error_("Failed whilst trying to fork."));
		if (id == 0)
			firstborn(envp);
		waitpid(id, NULL, 0);
	}
	papi(envp);
	return (SUCCESS);
}

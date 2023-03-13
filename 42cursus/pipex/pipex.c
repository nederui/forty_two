/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:44:02 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/13 00:00:12 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "unistd.h"

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

int	ft_setup(char **argv, char **envp)
{
	if (!ft_loadfiles(argv) || !ft_loadcmds(argv) \
	|| !ft_load_paths(argv, envp) || !ft_prep_paths())
		return (0);
	// ft_debug_path();
	return (1);
}

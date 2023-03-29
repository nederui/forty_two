/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 00:18:05 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/29 01:15:54 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
goes through the list of possible paths to find the first valid path to each
command passed as argument, saving each one on success
*/
int	ft_validate_paths(char **paths, char **valid_path)
{
	int	i;

	i = 0;
	while (paths[i] != 0)
	{
		if (!access(paths[i], F_OK))
		{
			*valid_path = ft_strdup(paths[i]);
			if (!valid_path)
				return (ft_error("Memory allocation error, \
		whilst saving the correct path for the first command."));
			break ;
		}
		i++;
	}
	return (SUCCESS);
}

/*
makes use of the modified version of 'ft_strjoin' to attach each command
passed as argument to every possible 'envp' path
*/
int	ft_append_cmds(char **paths, char **command)
{
	int	i;

	i = -1;
	while (paths[++i])
	{
		(paths[i]) = \
			ft_strjoin_ppx(paths[i], command[0]);
		if (!paths[i])
			return (ft_error("Memory allocation error, \
			whilst loading the envp paths."));
	}
	return (SUCCESS);
}

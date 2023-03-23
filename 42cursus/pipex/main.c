/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/23 02:00:23 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	ft_setup(char **argv, char **envp)
{
	if (!ft_access_files(argv) || !ft_load_cmds(argv) \
	|| !ft_load_paths(envp) || !ft_append_cmds() || !ft_validate_paths())
		return (0);
	if (!pipex()->valid_path[0])
		return (ft_error("1"));
	if (!pipex()->valid_path[1])
		return (ft_error("2"));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_error("Invalid number of arguments."));
	if (!ft_setup(argv, envp))
		return (0);
	ft_plumbing(envp);
	ft_exit();
	return (0);
}

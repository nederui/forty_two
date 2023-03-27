/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/27 20:08:49 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
validates each argument passed on launch, by parsing to the pipex() structure
through distinct functions;
returns '0' and a custom message when an error occurs and '1' on success
*/
int	ft_setup(char **argv, char **envp)
{
	if (!ft_access_files(argv) || !ft_load_cmds(argv) \
	|| !ft_load_paths(envp) || !ft_append_cmds() || !ft_validate_paths())
		return (FAILURE);
	if (!pipex()->valid_path[0])
		return (ft_error("1"));
	if (!pipex()->valid_path[1])
		return (ft_error("2"));
	return (SUCCESS);
}

/*
the program starts with two checks: if it was only given six arguments and,
if so, if both files and commands (provided as an argument) are valid. it then
boots up the program through ft_plumbing
*/
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_error("Invalid number of arguments."));
	if (!ft_setup(argv, envp))
		return (FAILURE);
	ft_plumbing(envp);
	ft_exit();
	return (0);
}

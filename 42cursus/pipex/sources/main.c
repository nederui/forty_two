/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/04/25 15:51:33 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

// checks if any of the commands passed as argument is invalid
int check_null_cmds(void)
{
	if (!pipex()->cmd_one[0] || !pipex()->cmd_two[0])
		return (error_("zsh: permission denied:"));
	if (!pipex()->valid_path[0])
		return (error_("invalid_cmd_one"));
	if (!pipex()->valid_path[1])
		return (error_("invalid_cmd_two"));
	return (1);
}

/*
the program starts with two checks: if it was only given six arguments and,
if so, if both files and commands (provided as an argument) are valid. 
it then boots up the program through plumbing() and it makes a third check
afterwards, in case it was passed an invalid command; this check happens last,
in case only one of the commands is invalid - the other should be still executed;
lastly, it exits the program in a clean way through exit_()
*/
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (error_("Invalid number of arguments."));
	if (!setup(argv, envp))
		return (FAILURE);
	plumbing(envp);
	if (!check_null_cmds())
		return(FAILURE);
	exit_();
	return (0);
}

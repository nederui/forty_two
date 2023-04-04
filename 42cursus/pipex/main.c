/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/29 18:01:58 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int check_null_cmds(void)
{
	if (!pipex()->valid_path[0])
		return (error_("1"));
	if (!pipex()->valid_path[1])
		return (error_("2"));
	return (1);
}

/*
the program starts with two checks: if it was only given six arguments and,
if so, if both files and commands (provided as an argument) are valid. it then
boots up the program through plumbing
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

/*
to do:
handle < infile "./cat" | "wc" file2 >		???

handle < infile "" | "" file2 >
handle < infile "notexistent" | "wc" file2 >
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/29 01:23:28 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

/*
to do:
handle < infile "" | "" file2 >
handle < infile "./cat" | "wc" file2 >
handle < infile "notexistent" | "wc" file2 >
*/

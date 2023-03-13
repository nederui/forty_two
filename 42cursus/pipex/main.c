/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/13 21:06:45 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_error("Invalid number of arguments."));
	if (!ft_setup(argv, envp))
		return (0);
	// supermario();
	// ft_attempt_exec(pipex()->paths, argv, envp);
	// ft_do_the_stuff();
	// ft_free_memory();
	// ft_clean_exit();
	return (0);
}

/*

./pipex infile "grep a1" "wc -w" outfile

a) check infile's fd
b) check(/create) outfile's fd
c) interpret & save cmd1 & cmd2
d) handle PATH= (run, save, split)
e) attach '/' to the possible paths

// fork() / pipe() / wait() / dup()
f) find cmd1 & cmd2's locations
g) save the result from cmd1
h) execute cmd2 on cmd1's result

*/
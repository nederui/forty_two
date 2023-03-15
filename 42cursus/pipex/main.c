/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/15 01:35:01 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_setup(char **argv, char **envp)
{
	if (!ft_access_files(argv) || !ft_load_cmds(argv) \
	|| !ft_load_paths(argv, envp) || !ft_prep_paths() || !ft_find_true_path())
		return (0);
	ft_debug_setup();
	if (!pipex()->true_path[0] || !pipex()->true_path[1])
		return (ft_error("Could not find the command passed as argument."));
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_error("Invalid number of arguments."));
	if (!ft_setup(argv, envp))
		return (0);
	// plumbing(argv, envp);
	// free_memory
	// clean exit
	return (0);
}

/*

./pipex infile "grep a1" "wc -w" outfile

a) check infile's fd
b) check(/create) outfile's fd
c) interpret & save cmd1 & cmd2
d) handle PATH= (run, save, split)
e) attach '/<command>' to the possible paths
f) access() -> find the correct cmd's path

// fork() / pipe() / wait() / dup()

) save the result from cmd1
) execute cmd2 on cmd1's result
)
*/
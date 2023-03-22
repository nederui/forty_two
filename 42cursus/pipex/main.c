/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/22 01:30:39 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
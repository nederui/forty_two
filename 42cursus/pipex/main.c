/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:59:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/08 00:43:53 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
*/
int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		return (ft_error("Invalid number of arguments."));
	// if (!ft_loadfiles(argv) || !ft_loadcmds(argv))
	// 	return (0);
	ft_load_env_paths("path", argv, envp);
	ft_save_paths();
	// ft_do_the_stuff();
	// ft_free_memory();
	// ft_clean_exit();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:31:56 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/08 00:41:18 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ************************************************************************** */

# include "../libft/libft.h"

/* ************************************************************************** */
// STRUCTURES
typedef struct s_pipex
{
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	char	**cmd_one;
	char	**cmd_two;
	char	*envp;
	char	**paths;

}	t_pipex;

/* ************************************************************************** */

t_pipex		*pipex(void);
int			ft_loadfiles(char **argv);
int			ft_loadcmds(char **argv);
void		ft_load_env_paths(char *path, char **argv, char **envp);
void		ft_save_paths(void);

int			ft_error(char *message);
void		ft_freewillie(void);
void		ft_exit(void);
char		*ft_strsandwich(char *ham, char *bread, int index);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:31:56 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/14 00:00:24 by nfilipe-         ###   ########.fr       */
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
	char	**paths;
	char	**paths2;
	int		inlet[2];
	int		id;

}	t_pipex;

/* ************************************************************************** */
// SETUP
int			ft_setup(char **argv, char **envp);
int			ft_load_files(char **argv);
int			ft_load_cmds(char **argv);
int			ft_load_paths(char **argv, char **envp);
int			ft_prep_paths(void);

// CORE
int			supermario(char **argv, char **envp);
int			ft_attempt_exec(char **paths, char **argv, char **envp);

// UTILITIES
t_pipex		*pipex(void);
void		ft_debug_setup(void);
char		*ft_strjoin_pipex(char *original_path, char *dash);

// WIP
int			ft_error(char *message);
void		ft_freewillie(void);
void		ft_exit(void);
char		*ft_strsandwich(char *ham, char *bread, int index);

#endif

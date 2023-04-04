/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:31:56 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/29 01:11:30 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* ************************************************************************** */

# include "libft/includes/libft.h"

/* ************************************************************************** */
// DEFINES
# define SUCCESS 1
# define FAILURE 0

/* ************************************************************************** */
// DEBUG

// # define malloc(x) NULL

/* ************************************************************************** */
// STRUCTURES
typedef struct s_pipex
{
	int		fd[2];
	char	**cmd_one;
	char	**cmd_two;
	char	**paths;
	char	**paths2;
	char	*valid_path[2];
	int		p1pe[2];
}	t_pipex;

/* ************************************************************************** */
// SETUP
int			setup(char **argv, char **envp);
int			access_files(char **argv);
int			load_cmds(char **argv);
int			load_paths(char **envp);
int			check_args_access(void);
int			check_append_validate(void);
int			append_cmds(char **paths, char **command);
int			validate_paths(char **paths, char **valid_path);
int			check_null_cmds(void);

// CORE
int			plumbing(char **envp);
int			papi(char **envp);
int			firstborn(char **envp);
int			leastfavorite(char **envp);

// UTILITIES
t_pipex		*pipex(void);
char		*strjoin_ppx(char *original_path, char *dash);
void		freewillie(char **array);
int			error_(char *message);
void		exit_(void);

#endif

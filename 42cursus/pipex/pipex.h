/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:31:56 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/17 02:55:31 by nfilipe-         ###   ########.fr       */
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
	// char	*files[2];
	int		fd[2];
	char	**cmd_one;
	char	**cmd_two;
	char	**paths;	//	free'd
	char	**paths2;	//	free'd
	char	*valid_path[2];
	int		p1pe[2];
	int		pip3[2];
}	t_pipex;

/* ************************************************************************** */
// SETUP
int			ft_setup(char **argv, char **envp);
int			ft_access_files(char **argv);
int			ft_load_cmds(char **argv);
int			ft_load_paths(char **argv, char **envp);
int			ft_append_cmds(void);
int			ft_validate_paths(void);

// CORE
int			ft_plumbing(char **envp);
int			ft_papi(char **envp);
int			ft_firstborn(char **envp);
int			ft_secondchild(char **envp);
// int			ft_switcheroo(void);

// UTILITIES
t_pipex		*pipex(void);
void		ft_debug_setup(void);
char		*ft_strjoin_ppx(char *original_path, char *dash);
void		ft_freewillie(char **array);

// WIP
int			ft_error(char *message);
//void		ft_exit(void);

#endif

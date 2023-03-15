/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 19:31:56 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/03/15 01:49:18 by nfilipe-         ###   ########.fr       */
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
	int		fds[2];
	char	**cmd_one;
	char	**cmd_two;
	char	**paths;	//	free'd
	char	**paths2;	//	free'd
	char	*true_path[2];
	int		inlet[2];
	int		outlet[2];
}	t_pipex;

/* ************************************************************************** */
// SETUP
int			ft_setup(char **argv, char **envp);
int			ft_access_files(char **argv);
int			ft_load_cmds(char **argv);
int			ft_load_paths(char **argv, char **envp);
int			ft_prep_paths(void);
int			ft_find_true_path(void);

// CORE
int			ft_plumbing(char **envp);
int			ft_papi(char **envp);
int			ft_firstborn(char **envp);
int			ft_secondchild(char **envp);
int			ft_switcheroo(void);

// UTILITIES
t_pipex		*pipex(void);
void		ft_debug_setup(void);
char		*ft_strjoin_ppx(char *original_path, char *dash);
void		ft_freewillie(char **array);

// WIP
int			ft_error(char *message);
//void		ft_exit(void);

#endif

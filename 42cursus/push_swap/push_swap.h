/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/15 23:47:35 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
typedef struct s_swap
{
	long	integer[65000];
	int		stack_len;
	int		status;
}	t_swap;

/* ************************************************************************** */
// SETUP
int			setup(char **argv);
int			check_digits(char *argument);
int			check_integer(long number);
int			check_duplicate(long number);
int			stack_it(long number);

// CORE

// UTILITIES
t_swap		*swap(void);
long		atoi_pswap(char *str);

void		freewillie(char **array);
int			error_(char *argument, char *message);
void		exit_(void);

#endif

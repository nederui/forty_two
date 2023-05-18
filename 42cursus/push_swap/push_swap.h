/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/18 18:12:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */

# include "libft/includes/libft.h"
# include <stdint.h>

/* ************************************************************************** */
// DEFINES
# define SUCCESS 1
# define FAILURE 0

typedef int long t_ptr;

/* ************************************************************************** */
// DEBUG

// # define malloc(x) NULL

/* ************************************************************************** */
// STRUCTURES
typedef struct s_swap
{

	int				stack_len;
	int				status;
	struct s_list	*int_lst;
}					t_swap;

/* ************************************************************************** */
// SETUP
int			setup(char **argv);
int			check_digits(char *argument);
int			check_integer(long number);
int			check_duplicate(int number);
int			stack_it(int number);

// CORE

// UTILITIES
t_swap		*swap(void);
long		atoi_pswap(char *str);

void		freewillie(char **array);
int			error_(char *argument, char *message);
void		exit_(void);

#endif

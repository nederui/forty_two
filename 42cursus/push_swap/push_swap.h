/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/22 18:56:52 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* ************************************************************************** */
// INCLUDES

# include "libft/includes/libft.h"
# include <stdint.h>

/* ************************************************************************** */
// DEFINITIONS

# define SUCCESS 1
# define FAILURE 0

typedef int long t_ptr;

/* ************************************************************************** */
// DEBUG

// # define malloc(x) NULL
# define HERE write(1, "HERE.\n", 6)
# define THERE write(1, "THERE.\n", 7)

/* ************************************************************************** */
// STRUCTURES

typedef struct s_swap
{
	char			**arguments;
	int				stack_len;
	int				status;
	struct s_list	*head_a;
	struct s_list	*head_b;
}					t_swap;

/* ************************************************************************** */
// SETUP

int			validate_arguments(char **argv);
int			check_digits(char *argument);
int			check_spaces(char *argument);
int			save_arg_array(char	*argument);
int			check_integer(long number);
int			check_duplicate(int number);

int			stack_it(int number);

// CORE
t_swap		*swap(void);

// UTILITIES
long		atoi_pswap(char *str);

void		print_stack(t_list *stack);
void		clear_stack(t_list *stack);

void		freewillie(char **array);
int			error_(void);
void		exit_(void);

#endif

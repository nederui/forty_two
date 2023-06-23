/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/23 17:28:50 by nfilipe-         ###   ########.fr       */
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

typedef int long	t_ptr;

/* ************************************************************************** */
// DEBUG

// # define malloc(x) NULL
# define HERE write(1, "HERE.\n", 6)
# define THERE write(1, "THERE.\n", 7)

/* ************************************************************************** */
// STRUCTURES

typedef struct s_ps
{
	char			**arguments;
	int				stack_len;
	int				status;
	struct s_list	*head_a;
	struct s_list	*head_b;
	int				lowest_value;
	int				lowest_pos;
}					t_ps;

/* ************************************************************************** */
// SETUP

int		validate_arguments(char **argv);
int		check_digits(char *argument);
int		check_spaces(char *argument);
int		save_arg_array(char	*argument);
int		check_integer(long number);
int		check_duplicate(int number);
int		stack_it(int number);

// SORTING
void	sort_it(void);
void	sort_three(void);
void	sort_four_five(void);
void	sir_sort_a_lot(void);

// SORTING UTILITIES
int		is_it_sorted(void);
void	push_lowest_to_b(void);
void	find_lowest_value(void *value);
int		find_lowest_pos(t_list *lst);
void	place_lowest_on_top(int position);

// MOVES
void	push(t_list **origin, t_list **desstination);
void	pa(void);
void	pb(void);
void	swap(t_list **stack);
void	sa(void);
void	sb(void);
void	rotate(t_list **stack);
void	ra(void);
void	rb(void);
void	reverse(t_list **stack);
void	rra(void);
void	rrb(void);


// UTILITIES
t_ps	*p_s(void);
long	atoi_pswap(char *str);
void	print_stacks(void);
void	clear_stack(t_list *stack);
void	freewillie(char **array);
int		error_(void);
void	exit_(void);

#endif

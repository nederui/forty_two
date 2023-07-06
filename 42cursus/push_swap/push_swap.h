/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:43:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/07/06 19:09:59 by nfilipe-         ###   ########.fr       */
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
# define GO_UP 1
# define GO_DOWN 0

typedef int long	t_ptr;

typedef struct s_ps
{
	int				stack_len;
	struct s_list	*stack_a;
	struct s_list	*stack_b;
	struct s_list	*clone_a;
	struct s_list	*clone_b;
	int				chunk_size;
}					t_ps;

/* ************************************************************************** */
// DEBUG

// # define malloc(x) NULL
// # define HERE write(1, "HERE.\n", 6)
// # define THERE write(1, "THERE.\n", 7)

/* ************************************************************************** */
// SETUP

int		validate_arguments(int argc, char **argv);
int		check_digits(char *argument);
int		check_spaces(char *argument);
int		validate_arg_array(int argc, char *argument);
int		check_arg_len(char *arg);
int		check_integer(long number);
int		check_duplicate(int number);
int		stack_it(int argc, int number);

// SORTING
void	sort_it(void);
void	sort_three(void);
void	sort_four_five(void);
void	sir_sort_a_lot(void);
void	sort_clone(t_list *stack);

// SORTING UTILITIES
int		is_it_sorted(t_list *stack);
int		find_lowest_number(t_list *lst);
int		find_highest_number(t_list *lst);
void	to_the_top(int index);
void	to_the_top_of_b(int index);
int		get_proximity(int index);
int		set_chunks(int chunks);
int		find_ref_nbr(t_list *stack);
int		push_lowest_chunk(t_list *stack, int ref_nbr);
void	push_highest_chunk(void);
int		validate_last_chunk(void);
int		get_number(t_list *lst, int index);

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
void	clear_stack(t_list *stack);
void	freewillie(char **array);
int		error_(void);
void	exit_(void);

// DEBUG
void	print_stacks(void);
void	print_clone(void);

#endif

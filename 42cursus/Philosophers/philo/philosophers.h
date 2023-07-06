/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:32:20 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/07/06 18:34:12 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/* ************************************************************************** */
// INCLUDES


/* ************************************************************************** */
// DEFINITIONS

# define SUCCESS 1
# define FAILURE 0

// typedef int long	t_ptr;

typedef struct s_philo
{

}					t_philo;

/* ************************************************************************** */
// DEBUG

// # define malloc(x) NULL
# define HERE write(1, "HERE.\n", 6)
# define THERE write(1, "THERE.\n", 7)

/* ************************************************************************** */
// SETUP

// UTILITIES
t_philo	*philo(void);
int		error_(void);
void	exit_(void);

// DEBUG

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 17:11:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* ************************************************************************** */

char	*get_next_line(int fd);
int		ft_findnewline(char *string);
char	*ft_freebuffer(char *buffer);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strlen_gnl(const char *string);

#endif
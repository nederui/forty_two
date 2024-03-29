/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 00:34:35 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/11 15:27:37 by nfilipe-         ###   ########.fr       */
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
char	*ft_freebuffer(char *buffer, int fd);
char	*ft_strjoin_gnl(char *line, char *buffer);
int		ft_strlen_gnl(const char *string);

#endif
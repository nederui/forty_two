/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:08:52 by egodinho          #+#    #+#             */
/*   Updated: 2022/11/28 21:13:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include	<stdlib.h>
# include	<unistd.h>
# include	<stdio.h>
# include	<strings.h>
# include	<fcntl.h>

size_t	strlen_gnl(const char *s);
char	*strchr_gnl(char *str, int c);
char	*strjoin_gnl(char *s1, char *s2);
char	*fun_get_line(char *text);
char	*get_save(char *text);
char	*read_and_join(int fd, char *save);
char	*get_next_line(int fd);

#endif
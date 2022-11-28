/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:57:52 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 04:40:59 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ************************************************************************** */

# include <unistd.h>

/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/* ************************************************************************** */

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t buffer);
size_t	ft_strlcat(char *dst, const char *src, size_t buffer);
void	*ft_memset(void *b, int c, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_newline_finder(char *pouch);
void	ft_line_generator(char *line, char *pouch);
void	ft_add_to_pouch(char *pouch, char *buffer, int char_read);

#endif
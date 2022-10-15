#ifndef LIBFT_H
#define LIBFT_H

/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
// #include "libft.h"

/* ************************************************************************** */

// #define _SIZE_T
// typedef __SIZE_TYPE__ size_t;
// typedef unsigned size_t;

/* ************************************************************************** */

int ft_atoi(const char *str);
void    bzero(void *s, size_t n);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int	ft_strcmp(char *s1, char *s2);
size_t	ft_strlen(char *str);
int	ft_strncmp(char *s1, char *s2, unsigned int n);

#endif

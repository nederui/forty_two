/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:45:17 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/20 20:05:58 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTPRINTF_H
# define FTPRINTF_H

/* ************************************************************************** */

# include <unistd.h>
# include <stdarg.h>

/* ************************************************************************** */

typedef unsigned long	t_ul;

HEX = "0123456789abcdef";

/* ************************************************************************** */


int		ft_converter(double number, char *base, double size);
int		ft_format_identifier(char c, va_list *args);
int		ft_printf(const char *format_string, ...);
int		ft_putchar_int(char c);
int		ft_putstr_int(char *s);


#endif
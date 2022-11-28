/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:45:17 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/27 19:49:15 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ************************************************************************** */

# include <stdarg.h>
# include <stdint.h>

/* ************************************************************************** */

# define DEC "0123456789"
# define HEX_UP "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"

/* ************************************************************************** */

int	ft_format_identifier(char c, va_list *args);
int	ft_number_converter(long number, char *base, long size);
int	ft_ptr_converter(uintptr_t number);
int	ft_printf(const char *format_string, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);

#endif
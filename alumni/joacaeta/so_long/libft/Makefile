# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 17:42:04 by joacaeta          #+#    #+#              #
#    Updated: 2022/10/20 20:38:50 by joacaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SO = libft.so

SRCS =	$(wildcard ./*.c)

OBJS = $(SRCS:.c=.o)

.c.o : libft.h get_next_line.h get_next_line_bonus.h
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

libft.a: $(OBJS)
	ar rcs libft.a $(OBJS)

all:	libft.a

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f libft.a

re:		fclean all

.PHONY: clean fclean re all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 14:36:20 by nfilipe-          #+#    #+#              #
#    Updated: 2022/11/15 03:22:03 by nfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh				   
# avoids trouble with any 'SHELL'-named variable

.SUFIXES:					   
.SUFIXES:	.c .o .h .a .so	   
# deletes the default suffixes
# defines our suffix list

SRCS	=	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c	ft_isprint.c \
			ft_memchr.c	ft_memcmp.c	ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
			ft_strnstr.c ft_strrchr.c \
			ft_bzero.c ft_atoi.c ft_itoa.c ft_tolower.c ft_toupper.c \
			ft_strdup.c ft_calloc.c ft_strtrim.c ft_substr.c ft_strjoin.c \
			ft_split.c ft_strmapi.c ft_striteri.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
# our complete sources list

BONUS	=	ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstadd_front.c \
			ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
# our complete bonus list

NAME 	=	libft.a
SRCS.O	=	$(SRCS:.c=.o)
BONUS.O	=	$(BONUS:.c=.o)
CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I.
# our compiler & flags

%.o:	%.c libft.h ; $(CC) -c $(CFLAGS) -o $@ $<

# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
							   
# '%' stands for the same stem that was matched by the ‘%’ in the target
							   
# '$@' the file name of the target of the rule

# '$<' the name of the first prerequisite.	

.PHONY:	all
all:		$(NAME)

$(NAME):	$(SRCS.O) ; @echo compiling \& linking sources + building $(NAME)
			ar -rcs $(NAME) $(SRCS.O) ; 

.PHONY:	bonus
bonus:		$(NAME) $(BONUS.O) ; @echo compiling and linking bonus
			ar -rcs $(NAME) $(BONUS.O)

.PHONY:	clean
clean:		; @echo removing all objects
			rm -f $(SRCS.O) $(BONUS.O)

.PHONY:	fclean
fclean:		clean ; @echo removing $(NAME)
			rm -f $(NAME)

.PHONY:	re
re:			fclean $(NAME)

.PHONY:	info
info:	
		@echo Makefile for \'libft.a\' v0.8.15112022 - work in progress
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(SRCS.O) $(BONUS)

#	A phony target is one that is not really the name of a file; rather it \
	is just a name for a recipe to be executed when you make an explicit \
	request.It mainly avoids a conflict with a file of the same name

.SILENT:	
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:53:58 by nfilipe-          #+#    #+#              #
#    Updated: 2022/11/22 21:00:34 by nfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh 
# avoids trouble with any 'SHELL'-named variable

.SUFIXES:					   
.SUFIXES:	.a .c .h .o
# deletes the default suffixes
# defines our suffix list

SRCS	=	ft_format_identifier.c ft_number_converter.c ft_ptr_converter.c \
			ft_printf.c ft_putchar_int.c ft_putstr_int.c
# the complete list of the source files to be used

OBJECTS	=	ft_format_identifier.o ft_number_converter.o ft_ptr_converter.o \
			ft_printf.o ft_putchar_int.o ft_putstr_int.o
# the complete list of all the objects to be created
 
NAME 	=	libftprintf.a
# the name of the executable built by this Makefile

CC		=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror -I. -g -fsanitize=address
# compiler & flags to be used
# '-O2' Apply almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. \
This option generally increases the time needed to compile.
# (-I<dir>) adds the current directory to include search path for libft.h

all:		$(NAME) ;
# our default goal - it compiles the entire program (except bonus)

$(NAME):	$(SRCS.O)
			@echo compiling \& linking sources + building $(NAME)
			ar -crs $(NAME) $(SRCS.O) ; 
# ar creates an index to the symbols defined in relocatable object modules \
in the archive when you specify the modifier ‘s’. Once created, this index \
is updated in the archive whenever ar makes a change to its contents \
An archive with such an index speeds up linking to the library, and allows \
routines in the library to call each other without regard to their \
placement in the archive

# 'r' inserts the files member into archive (with replacement)
# 'c' creates the archive. The specified archive is always created if it did \
not exist, when you request an update.
# 's' adds an index to the archive, or update it if it already exists

SRCS.O:		$(SRCS) ft_printf.h
			$(CC) $(CFLAGS) -c -o $(SRCS)
# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.

clean:		; @echo removing all objects
			rm -rf $(SRCS.O)

fclean:		clean ; @echo removing $(NAME)
			rm -rf $(NAME)
# 'rm' removes files
# '-f' forces removal (ignores nonexistent files and arguments)

re:			fclean $(NAME)

info:	
		@echo Makefile for \'libftprintf.a\' v1.0.21112022 by nfilipe-

acknowledgements:	
					@echo my deepest gratitude to my coleagues @ 42 Lisboa: \
					amak, fmouronh, matde-je, oharoon, rteles-f
					@echo for their insight, tips and enthusiasm
					@echo \>\> special shout-out to oharoon, \
					who pointed me in the right direction on this project

.PHONY:	all clean fclean re info acknowledgements
# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name

.SILENT:	
# 'make' will not print the recipe used to remake those particular files \
before executing them.
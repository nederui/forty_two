# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/24 20:43:48 by nfilipe-          #+#    #+#              #
#    Updated: 2023/06/26 00:21:53 by nfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# SAFEGUARDS

# to avoid problems with any 'SHELL'-named variable
SHELL	=	/bin/bash 

# to delete the default suffixes & define our suffix list
.SUFIXES:
.SUFIXES:	.a .c .h .o

################################################################################
# ARGUMENTS

# the name of the executable built by this Makefile
NAME 	=	push_swap

# compiler (cc) & flags to be used
# '-O2' applies almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. This option \
generally increases the time needed to compile.
# '-I<dir>' adds the current directory to include search path for 'push_swap.h'
# 'DEBUG' flags will compile the code with debug symbols (-g) & detect memory \
access error such as use-after-free and memory leaks (-fsanitize=address)
CC		=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror -I.
#DEBUG	=	-g -fsanitize=address

# 'rm -rf' forced file removal (ignores nonexistent files and arguments), \
including directories and their contents, recursively (-r)
REMOVE	=	rm -rf

################################################################################
# SOURCES

# the complete list of the source files to be used
SRCS	=	sources/main.c													\
			sources/setup.c				sources/setup_ii.c					\
			sources/utilities.c			sources/utilities_ii.c				\
			\
			sources/moves/push.c		sources/moves/swap.c				\
			sources/moves/rotate.c		sources/moves/reverse.c				\
			\
			sources/sorting/sort_it.c										\
			sources/sorting/sort_three_four_five.c							\
			sources/sorting/sir_sort_a_lot.c								\
			sources/sorting/sorting_utilities.c								\
			sources/sorting/sorting_utilities_ii.c
			
# the complete list of all the objects to be created
OBJECTS	=	$(SRCS:.c=.o)

# libft's path
LIBFT	=	libft/libft.a

# project's header file
INCLUDE	=	push_swap.h

################################################################################
# RULES

# our default goal - it compiles the entire program
all:		$(NAME)

# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.
%.o: %.c
			$(CC) $(CFLAGS) -I$(INCLUDE) -O2 -c $< -o $@
			
# 'make -C' executes libft's Makefile
# 'ranlib' to run our libft.a, as it is a static library (.a file)
$(NAME):	$(OBJECTS)
			@make -C libft
			@echo push_swap: compiling \& linking sources
			@echo building $(NAME)
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
#			@ranlib -lft $(NAME)

# OBJECTS:	$(SRCS) $(INCLUDE)
# 			$(CC) $(DEBUG) $(CFLAGS) -c -o $(SRCS)

clean:
			@make clean -C libft
			$(REMOVE) $(OBJECTS)
			@echo removing all objects


fclean:		clean
			@make fclean -C libft
			$(REMOVE) $(NAME)
			@echo removing $(NAME)

re:			fclean $(NAME)

################################################################################
# SPECIAL RULES

info:	
			@echo Makefile for \'push_swap\' v0.0.15052023 by nfilipe-

acknowledgments:	
			@echo my deepest gratitude to my coleagues @ 42 Lisboa: fmouronh, \
			gpardini and plopes-c for their insight, tips and enthusiasm
			@echo \>\> special shout-out to ___, who pointed me in the \
			right direction on this project	

# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name
.PHONY:		all clean fclean re info acknowledgments

# 'make' will not print the recipe used to remake those particular files \
before executing them.
.SILENT:

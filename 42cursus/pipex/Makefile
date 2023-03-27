# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 16:02:21 by nfilipe-          #+#    #+#              #
#    Updated: 2023/03/27 19:37:26 by nfilipe-         ###   ########.fr        #
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
NAME 	=	pipex

# compiler (cc) & flags to be used
# '-O2' applies almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. This option \
generally increases the time needed to compile.
# '-I<dir>' adds the current directory to include search path for 'pipex.h'
# 'DEBUG' flags will compile the code with debug symbols (-g) & detect memory \
access error such as use-after-free and memory leaks (-fsanitize=address)
CC		=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror -I.
DEBUG	=	-g -fsanitize=address

# 'rm -rf' forced file removal (ignores nonexistent files and arguments), \
including directories and their contents, recursively (-r)
REMOVE	=	rm -rf

################################################################################
# SOURCES

# the complete list of the source files to be used
SRCS	=	main.c	setup.c	plumbing.c	utilities.c

# the complete list of all the objects to be created
OBJECTS	=	$(SRCS:.c=.o)

# libft's path
LIBFT	=	libft/libft.a

# project's header file
INCLUDE	=	pipex.h

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
			@echo pipex: compiling \& linking sources
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
			@echo Makefile for \'pipex\' v0.3.27032023 by nfilipe-

acknowledgments:	
			@echo my deepest gratitude to my coleagues @ 42 Lisboa for their \
			insight, tips and enthusiasm
			@echo \>\> special shout-out to amak, who pointed me in the \
			right direction on this project	

# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name
.PHONY:		all clean fclean re info acknowledgments

# 'make' will not print the recipe used to remake those particular files \
before executing them.
.SILENT:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:53:58 by nfilipe-          #+#    #+#              #
#    Updated: 2022/11/23 13:12:26 by nfilipe-         ###   ########.fr        #
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
NAME 	=	libftprintf.a

# compiler (cc) & flags to be used
# '-O2' applies almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. This option \
generally increases the time needed to compile.
# '-I<dir>' adds the current directory to include search path for 'libft.h'
# 'DEBUG' flags will compile the code with debug symbols (-g) & detect memory \
access error such as use-after-free and memory leaks (-fsanitize=address)
CC		=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror -I.
DEBUG	=	-g -fsanitize=address

# 'rm -rf' forced file removal (ignores nonexistent files and arguments), \
including directories and their contents, recursively (-r)
REMOVE	=	rm -rf

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
INDEX	=	ar -crs

################################################################################
# SOURCES

# the complete list of the source files to be used
SRCS	=	ft_format_identifier.c ft_number_converter.c \
			ft_ptr_converter.c ft_printf.c ft_putchar_int.c ft_putstr_int.c

# the complete list of all the objects to be created
OBJECTS	=	ft_format_identifier.o ft_number_converter.o \
			ft_ptr_converter.o ft_printf.o ft_putchar_int.o ft_putstr_int.o
 
# project's header file
INCLUDE	=	ft_printf.h

################################################################################
# RULES

# our default goal - it compiles the entire program (except bonus)
all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo compiling \& linking sources
			@echo building $(NAME)
			$(INDEX) $(NAME) $(OBJECTS)

# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.
OBJECTS:	$(SRCS) $(INCLUDES)
			$(CC) $(DEBUG) $(CFLAGS) -c -o $(SRCS)

clean:
			@echo removing all objects
			$(REMOVE) $(OBJECTS)

fclean:		clean
			@echo removing $(NAME)
			$(REMOVE) $(NAME)

re:			fclean $(NAME)

################################################################################
# SPECIAL RULES

info:	
			@echo Makefile for \'libftprintf.a\' v1.1.23112022 by nfilipe-

thanks:	
			@echo my deepest gratitude to my coleagues @ 42 Lisboa: amak, \
			drobert-, fmouronh, matde-je, oharoon, rteles-f for their \
			insight, tips and enthusiasm
			@echo \>\> special shout-out to oharoon, who pointed me in the \
			right direction on this project	

# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name
.PHONY:		all clean fclean re info thanks

# 'make' will not print the recipe used to remake those particular files \
before executing them.
.SILENT:	
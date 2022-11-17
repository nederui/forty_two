# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 19:53:58 by nfilipe-          #+#    #+#              #
#    Updated: 2022/11/17 17:30:50 by nfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh 
# avoids trouble with any 'SHELL'-named variable

.SUFIXES:					   
.SUFIXES:	.a .c .h .o
# deletes the default suffixes
# defines our suffix list

SRCS	=	
# the complete list of the source files to be used

SRCS.O	=	
# the complete list of all the objects to be created
 
NAME 	=	
# the name of the executable built by this Makefile

CC		=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror -I<dir>
# compiler & flags to be used
# '-O2' Apply almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. \
This option generally increases the time needed to compile.
# (-I<dir>) adds the current directory to include search path for libft.h

all:		$(NAME) ;
# our default goal - it compiles the entire program (except bonus)

$(NAME):	$(SRCS.O) ; @echo compiling \& linking sources + building $(NAME)
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

SRCS.O:		$(SRCS) libft.h
			$(CC) $(CFLAGS) -c -o $(SRCS)
# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.

clean:		; @echo removing all objects
			rm -f $(SRCS.O)

fclean:		clean ; @echo removing $(NAME)
			rm -f $(NAME)
# 'rm' removes files
# '-f' forces removal (ignores nonexistent files and arguments)

re:			fclean $(NAME)

info:	
		@echo Makefile for \'___\' v0.9.01122022 by nfilipe-

.PHONY:	all clean fclean re info
# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name

.SILENT:	
# 'make' will not print the recipe used to remake those particular files \
before executing them.
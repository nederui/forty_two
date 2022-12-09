# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 13:47:32 by nfilipe-          #+#    #+#              #
#    Updated: 2022/12/08 18:51:17 by nfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
# SAFEGUARDS

# to avoid problems with any 'SHELL'-named variable
SHELL	=	/bin/bash 

# to delete the default suffixes & define our suffix list
.SUFIXES:					   
.SUFIXES:	.ber .c .h .o

################################################################################
# ARGUMENTS

# the name of the executable built by this Makefile
NAME 	=	so_long

# compiler (cc) & flags to be used
# '-O2' applies almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. This option \
generally increases the time needed to compile.
# '-I<dir>' adds the current directory to include search path for 'libft.h'
# 'DEBUG' flags will compile the code with debug symbols (-g) & detect memory \
access error such as use-after-free and memory leaks (-fsanitize=address)
CC		=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror $(INCLUDE)
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
#INDEX	=	ar -crs

################################################################################
# SOURCES

# the complete list of the source files to be used
SRCS	=	

LIBFT 	=	libft/ft_isalnum.c		libft/ft_isalpha.c		libft/ft_isascii.c	\
			libft/ft_isdigit.c		libft/ft_isprint.c		libft/ft_memchr.c	\
			libft/ft_memcmp.c		libft/ft_memcpy.c		libft/ft_memmove.c	\
			libft/ft_memset.c		libft/ft_strchr.c		libft/ft_strlcat.c	\
			libft/ft_strlcpy.c		libft/ft_strlen.c		libft/ft_strncmp.c	\
			libft/ft_strnstr.c		libft/ft_strrchr.c		libft/ft_strdup.c	\
			libft/ft_strjoin.c		libft/ft_strmapi.c		libft/ft_striteri.c	\
			libft/ft_strtrim.c		libft/ft_substr.c		libft/ft_bzero.c	\
			libft/ft_split.c		libft/ft_atoi.c			libft/ft_itoa.c		\
			libft/ft_tolower.c		libft/ft_toupper.c		libft/ft_putstr_fd.c\
			libft/ft_putchar_fd.c	libft/ft_putendl_fd.c	libft/ft_calloc.c	\
			libft/ft_putnbr_fd.c	libft/ft_lstadd_back.c	libft/ft_lstnew.c	\
			libft/ft_lstdelone.c	libft/ft_lstadd_front.c	libft/ft_lstmap.c	\
			libft/ft_lstsize.c		libft/ft_lstiter.c		libft/ft_lstlast.c	\
			libft/ft_lstclear.c						\
			libft/utils/ft_putaddr.c				\
			libft/ft_printf/ft_printf.c				\
			libft/ft_printf/ft_format_identifier.c	\
			libft/ft_printf/ft_number_converter.c	\
			libft/ft_printf/ft_putchar_pf.c			\
			libft/ft_printf/ft_putstr_pf.c			\
			libft/ft_printf/ft_ptr_converter.c		\
			libft/get_next_line/get_next_line.c 	\
			libft/get_next_line/get_next_line_utils.c

# the complete list of all the objects to be created
OBJECTS	=	$(SRCS:.c=.o) $(LIBFT:.c=.o)
 
# project's header file
INCLUDE	=	-I includes/

MINILIBX=	minilibx

GFX		=	-Lminilibx -lmlx -framework OpenGL -framework AppKit

################################################################################
# RULES

%.o:		%.c
			$(CC) $(DEBUG) $(CFLAGS) -Imlx_linux -c $^ -o $@ -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit

# our default goal - it compiles the entire program (except bonus)
all:		gfx $(NAME)

gfx:		
			@echo checking/building MinilibX
#			@make -C $(MINILIBX)

$(NAME):	$(OBJECTS)
			@echo compiling \& linking sources
			@echo building $(NAME)
#			$(INDEX) $(NAME) $(OBJECTS)

# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.
OBJECTS:	$(SRCS) $(LIBFT) $(INCLUDE)
			
clean:
			@echo removing all objects
			make clean -C $(MINILIBX)
			$(REMOVE) $(OBJECTS)
#			make clean -C $(GFX)

fclean:		clean
			@echo removing $(NAME)
			$(REMOVE) $(NAME)

re:			fclean $(NAME)

################################################################################
# SPECIAL RULES

info:	
			@echo Makefile for \'so_long\' v0.1.07122022 by nfilipe-
			@echo
			@echo to run this program, add a map \(.ber file\) as a parameter: \
			\'.\/so_long \<map_name\>\.ber\'

acknowledgments:	
			@echo my deepest gratitude to my coleagues @ 42 Lisboa: amak, \
			drobert-, fmouronh, matde-je, mvenanci, oharoon, rteles-f for \
			their insight, tips and enthusiasm
			@echo \>\> special shout-out to rteles-f and mvenanci, who helped \
			me a great deal with get_next_line's logic \

# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name
.PHONY:		all clean fclean re info acknowledgments

# 'make' will not print the recipe used to remake those particular files \
before executing them.
.SILENT:	
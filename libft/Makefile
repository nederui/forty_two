# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/30 14:36:20 by nfilipe-          #+#    #+#              #
#    Updated: 2022/11/15 17:48:14 by nfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
   
# avoids trouble with any 'SHELL'-named variable

.SUFIXES:					   
.SUFIXES:	.a .c .h .o

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
CC	=	cc 
CFLAGS	=	-O2 -Wall -Wextra -Werror -I.

# our compiler & flags
# '-O2' Apply almost all of the supported optimization techniques that do \
not involve a tradeoff between program size and execution speed. \
This option generally increases the time needed to compile.
# (-I<dir>) adds the current directory to include search path for libft.h

.c.o: libft.h ; $(CC) -c $(CFLAGS) -o $@ $<

# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h

# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.
# '$@' the file name of the target of the rule
# '$<' the name of the first prerequisite.	

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

bonus:		$(NAME) $(BONUS.O) ; @echo compiling and linking bonus
			ar -crs $(NAME) $(BONUS.O)

clean:		; @echo removing all objects
			rm -f $(SRCS.O) $(BONUS.O)

fclean:		clean ; @echo removing $(NAME)
			rm -f $(NAME)

# 'rm' removes files
# '-f' forces removal (ignores nonexistent files and arguments)

re:			fclean $(NAME)

info:	
		@echo Makefile for \'libft.a\' v0.9.15112022 by nfilipe-

.PHONY:	all bonus clean fclean re info

# A phony target is one that is not really the name of a file; rather it \
is just a name for a recipe to be executed when you make an explicit \
request.It mainly avoids a conflict with a file of the same name

.SILENT:	

# 'make' will not print the recipe used to remake those particular files \
before executing them.
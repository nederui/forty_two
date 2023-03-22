

################################################################################
# SAFEGUARDS

# to avoid problems with any 'SHELL'-named variable
SHELL	=	/bin/bash 

# to delete the default suffixes & define our suffix list
.SUFIXES:					   
.SUFIXES:	.c .h .o

################################################################################
# ARGUMENTS

# the name of the executable built by this Makefile
NAME 	=	pipex

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

################################################################################
# SOURCES

# the complete list of the source files to be used
SRCS	=	main.c	setup.c	plumbing.c	utilities.c

# the complete list of all the objects to be created
OBJECTS	=	main.o	setup.o	plumbing.o	utilities.o

LIBFT	=	libft
# project's header file & libft's header file
INCLUDE	=	pipex.h -L./libft -lft

################################################################################
# RULES

# our default goal - it compiles the entire program
# 'make -C' executes libft's Makefile
# 'cp ./$(NAME)' to copy the libft.a to this program's main directory
# 'ranlib' to run our libft.a, as it is a static library (.a file)
all:		$(NAME)

$(NAME):	$(OBJECTS)
			@echo compiling \& linking sources
			@make -C $(LIBFT)
			@echo building $(LIBFT)
			@echo copying libft.a to $(NAME)'s main directory
			@cp libft/libft.a ./$(NAME)
			@echo building $(NAME)
			$(NAME) $(OBJECTS)
			@ranlib $(NAME)


# tells how to make ‘.o’ files from ‘.c’ files and makes all ‘.o’ files \
using this pattern rule also depend on libft.h
# '-c' preprocess, compile, and assemble only (i.e., don’t link)
# '-o' Direct output to the specified file.
OBJECTS:	$(SRCS) $(INCLUDE)
			$(CC) $(DEBUG) $(CFLAGS) -c -o $(SRCS)

clean:
			@echo removing all objects
			$(REMOVE) $(OBJECTS)
			@make clean -C $(LIBFT)


fclean:		clean
			@echo removing $(NAME)
			$(REMOVE) $(NAME)
			@make fclean -C $(LIBFT)


re:			fclean $(NAME)

################################################################################
# SPECIAL RULES

info:	
			@echo Makefile for \'pipex\' v0.8.22032023 by nfilipe-

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

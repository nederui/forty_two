NAME = libft.a

#name of the executable

functions = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
			ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c \
			ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c \
			ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_putnbr_fd.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_strmapi.c ft_striteri.c \
			ft_itoa.c ft_split.c \

#all the main functions

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

#bonus plus functions

functions_o = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o \
			ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
			ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o \
			ft_memset.o ft_strchr.o ft_strdup.o ft_strlcat.o \
			ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strnstr.o \
			ft_strrchr.o ft_tolower.o ft_toupper.o ft_substr.o \
			ft_strjoin.o ft_strtrim.o ft_putnbr_fd.o ft_putchar_fd.o \
			ft_putstr_fd.o ft_putendl_fd.o ft_strmapi.o ft_striteri.o \
			ft_itoa.o ft_split.o \

#functions objects

BONUS_o = ft_lstnew.o ft_lstadd_front.o ft_lstsize.o ft_lstlast.o \
		ft_lstadd_back.o ft_lstdelone.o ft_lstclear.o ft_lstiter.o ft_lstmap.o \

#bonus functions objects

CC = cc

CC_Flags = -Wall -Wextra -Werror

#allowed flags

all: $(NAME)

#default compiler

$(NAME): $(functions_o)
	ar -crs $(NAME) $(functions_o)

functions_o: $(functions) libft.h
	$(CC) $(CC_Flags) -c -o $(functions)

BONUS_o: $(BONUS) libft.h
	$(CC) $(CC_Flags) -c -o $(BONUS)

bonus: $(NAME) $(BONUS_o)
		ar -crs $(NAME) $(BONUS_o)

clean: ; @echo removing the objects 
	rm -f $(functions_o) $(BONUS_o)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re, bonus
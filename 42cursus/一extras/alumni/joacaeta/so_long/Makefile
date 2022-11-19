# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 17:48:32 by joacaeta          #+#    #+#              #
#    Updated: 2022/11/06 22:14:02 by joacaeta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
FLAGS := -Wall -Wextra -Werror -g #-fsanitize=address
LIBRARIES := -Llibft -lft
INCLUDE_DIRS := libft \
				src \
				inc \
				bonus \
				mlx_linux \
				.
INCLUDES := $(addprefix -I, $(INCLUDE_DIRS))
NAME := so_long
NAME_B  := so_long_bonus
SRCS := $(wildcard src/*.c)
SRCS_B := $(wildcard bonus/*.c)
OBJS := $(SRCS:.c=.o) $(MAIN:.c=.o)
OBJS_B := $(SRCS_B:.c=.o) $(MAIN:.c=.o)

MLX_LIB_DIR = mlx_linux/
MLX_INCLUDE = -Imlx_linux
MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: libft $(NAME)

bonus: libft $(NAME_B)

libft:
	make -C libft/

%.o : %.c
	$(CC) $(FLAGS) $(MLX_INCLUDE) -c $^ -o $@ $(INCLUDES)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) $^ $(MLX_FLAGS) $(LIBRARIES) -o $@ $(INCLUDES)

$(NAME_B) : $(OBJS_B)
	$(CC) $(FLAGS) $^ $(MLX_FLAGS) $(LIBRARIES) -o so_long $(INCLUDES)

clean:
	rm -f $(OBJS) $(OBJS_B)
	$(MAKE) -C libft/ clean

fclean:
	rm -f $(NAME) $(NAME_B)
	$(MAKE) -C libft/ fclean

re: fclean all

r:
	make && make clean && clear && ./so_long maps/map.ber

r2:
	make && make clean && clear && ./so_long maps/bigmap.ber

.PHONY: libft minilibx all bonus clean fclean re bonus

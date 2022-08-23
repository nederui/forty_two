CC=gcc
CFILES=$(shell find src -type f -name "*.c")
HEADERS_DIR=includes/
CFLAGS=-Wall -Wextra -Werror -I $(HEADERS_DIR)
CPPFLAGS=-O2
DEBUG_FLAGS=-Wall -Wextra -Werror
NAME=rush-02
OBJS=${CFILES:.c=.o}

all: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf src/*.o

fclean:
	rm -f $(NAME)

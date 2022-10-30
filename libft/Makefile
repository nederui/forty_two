NAME="libft.a"

$(NAME)

clean

fclean

re

all

cc -Wall -Wextra -Werror

-O2


SOURCES	=	radix.c\
			moves/rotate.c\
			moves/r_rotate.c\
			moves/swap.c\
			moves/push.c\
			attributter.c\
			special_cases.c\
			gen_ver.c\
			my_atoi.c\
			push_swap.c 
	
			

NAME 	=	push_swap
OBJECTS	=	$(SOURCES:.c=.o)
GCCW	=	@gcc -Wall -Wextra -Werror -Ifiles/ft_utils/ -I./ -g -fsanitize=address


%.o:		%.c
			$(GCCW) -c $^ -o $@

all:		$(NAME)

$(NAME): 	$(SOURCES)
			$(GCCW) $^ -o $@ 
			@clear && echo "\033[1;32m  ___  __   _  _  ____  __  __    ____  ____ \n / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(    \ \n( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  ) D (\n \___)\__/ \_)(_/(__)  (__)\____/(____)(____/"
clean:		
			@clear && echo "\033[1;33m  ___  __    ____   __   __ _  ____  ____ \n / __)(  )  (  __) / _\ (  ( \(  __)(    \ \n( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n \___)\____/(____)\_/\_/\_)__)(____)(____/"
			@rm -f $(OBJECTS)

fclean:		
			@clear && echo "\033[1;31m ____  ___  __    ____   __   __ _  ____  ____ \n(  __)/ __)(  )  (  __) / _\ (  ( \(  __)(    \ \n ) _)( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n(__)  \___)\____/(____)\_/\_/\_)__)(____)(____/"
			@rm -f $(OBJECTS)
			@rm -f $(NAME)

re:			fclean $(NAME)
			@clear && echo "\033[1;31m ____  ___  __    ____   __   __ _  ____  ____ \n(  __)/ __)(  )  (  __) / _\ (  ( \(  __)(    \ \n ) _)( (__ / (_/\ ) _) /    \/    / ) _)  ) D (\n(__)  \___)\____/(____)\_/\_/\_)__)(____)(____/\n\n\n\033[1;32m  ___  __   _  _  ____  __  __    ____  ____ \n / __)/  \ ( \/ )(  _ \(  )(  )  (  __)(    \ \n( (__(  O )/ \/ \ ) __/ )( / (_/\ ) _)  ) D (\n \___)\__/ \_)(_/(__)  (__)\____/(____)(____/"

.PHONY:	all clean fclean re
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = 0;
	if (argc == 2)
	{
		while (argv[1][lenght])
			lenght++;
		i = lenght - 1;
		while (argv[1][i] == 32 || argv[1][i] == 9)
			i--;
		lenght = i;
		while (argv[1][lenght] != 32 && argv[1][lenght] != 9)
			lenght--;
		lenght++;
		while (argv[1][lenght] != 32 && argv[1][lenght] != 9 && argv[1][lenght] != '\0')
		{
			write(1, &argv[1][lenght], 1);
			lenght++;
		}
	}
	write(1, "\n", 1);
	return (0);
}











// Assignment name  : last_word
// Expected files   : last_word.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that takes a string and displays its last word followed by a \n.

// A word is a section of string delimited by spaces/tabs or by the start/end of
// the string.

// If the number of parameters is not 1, or there are no words, display a newline.

// Example:

// $> ./last_word "FOR PONY" | cat -e
// PONY$
// $> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
// not$
// $> ./last_word "   " | cat -e
// $
// $> ./last_word "a" "b" | cat -e
// $
// $> ./last_word "  lorem,ipsum  " | cat -e
// lorem,ipsum$
// $>
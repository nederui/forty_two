#include <unistd.h>

void	ft_putchar(char number)
{
	int	n;

	n = number / 10 + 48;
	if (n != 48)
		write (1, &n, 1);
	n = number % 10 + 48;
	write (1, &n, 1);
	write(1, "\n", 1);
}

int	main(void)
{
	int	number;

	number = 1;
	while (number < 100)
	{
		if (number % 3 == 0 && number % 5 == 0)
			write(1, "fizzbuzz\n", 9);
		else if (number % 3 == 0)
			write(1, "fizz\n", 5);
		else if (number % 5 == 0)
			write(1, "buzz\n", 5);
		else
			ft_putchar(number);
		number++;
	}
	write (1, "buzz", 4);
	write(1, "\n", 1);
}

// Assignment name  : fizzbuzz
// Expected files   : fizzbuzz.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a program that prints the numbers from 1 to 100, each separated by a
// newline.

// If the number is a multiple of 3, it prints 'fizz' instead.

// If the number is a multiple of 5, it prints 'buzz' instead.

// If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

// Example:

// $>./fizzbuzz
// 1
// 2
// fizz
// 4
// buzz
// fizz
// 7
// 8
// fizz
// buzz
// 11
// fizz
// 13
// 14
// fizzbuzz
// [...]
// 97
// 98
// fizz
// buzz
// $>
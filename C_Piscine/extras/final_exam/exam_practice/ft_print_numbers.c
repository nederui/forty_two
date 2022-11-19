#include <stdio.h>

void	ft_print_numbers(void)
{
	char	a;

	a = 48;
	while (a < 58)
	{
		write(1, &a, 1);
		a++;
	}
}

// Assignment name  : ft_print_numbers
// Expected files   : ft_print_numbers.c
// Allowed functions: write
// --------------------------------------------------------------------------------

// Write a function that displays all digits in ascending order.

// Your function must be declared as follows:

// void	ft_print_numbers(void);

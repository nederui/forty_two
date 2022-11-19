#include "rush02.h"
#include <stdio.h>

int	hundreds(char hundred, int before)
{
	if (hundred != '0')
	{
		if (before == 1)
		{
			write(1, " ", 1);
		}
		print_nb('0', hundred);
		write(1, " ", 1);
		print_mag(3);
		return (1);
	}
	return (before);
}

int	decimals(char decimal, char unity, int before)
{
	int	sum;

	sum = (decimal - '0') * 10 + (unity - '0');
	if (sum == 0)
		return (before);
	if (sum < 21)
	{
		if (before == 1)
			write(1, " ", 1);
		print_nb(decimal, unity);
		return (1);
	}
	else
	{
		if (before == 1)
			write(1, " ", 1);
		print_nb(decimal, '0');
		if (unity != '0')
		{
			write(1, " ", 1);
			print_nb('0', unity);
		}
		return (1);
	}
	return (before);
}

int	main(int argc, char **argv)
{
	char	*array;
	int		mag;
	int		length;
	int		i;
	int		before;

	array = correctlength(argv[argc - 1]);
	length = ft_strlen(array);
	mag = length - 2;
	i = 0;
	before = 0;
	while (i < length)
	{
		before = hundreds(array[i], before);
		before = decimals(array[i + 1], array[i + 2], before);
		if (mag > 3)
		{
			write(1, " ", 1);
			print_mag(mag);
		}
		mag = mag - 3;
		i = i + 3;
	}
	write(1, "\n", 1);
}

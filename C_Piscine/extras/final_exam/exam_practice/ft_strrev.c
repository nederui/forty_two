#include <stdio.h>

char	*ft_strrev(char *str)
{
	int	lenght;
	int	pouch;
	int	i;

	i = 0;
	lenght = 0;
	pouch = 0;
	while (str[lenght])
		lenght++;
	while (i < lenght)
	{
		pouch = str[i];
		str[i] = str[lenght - 1];
		str[lenght - 1] = pouch;
		i++;
		lenght--;
	}
	return (str);
}

int	main(void)
{
	char str[] = "abcdefg";
	printf("%s", ft_strrev(str));
}
// Assignment name  : ft_strrev
// Expected files   : ft_strrev.c
// Allowed functions: 
// --------------------------------------------------------------------------------

// Write a function that reverses (in-place) a string.

// It must return its parameter.

// Your function must be declared as follows:

// char    *ft_strrev(char *str);
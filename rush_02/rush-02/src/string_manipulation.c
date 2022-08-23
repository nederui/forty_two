#include "rush02.h"

void	print_mag(int mag)
{
	char	*str;
	char	*to_print;
	int		i;

	str = malloc(sizeof(char) * mag + 1);
	str[0] = '1';
	i = 1;
	while (i < mag)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	to_print = find_key("numbers_specific.dict", str);
	free(str);
	ft_putstr(to_print);
	free(to_print);
}

void	print_nb(char a, char b)
{
	char	*to_print;
	char	*str;

	if (a == '0')
	{
		str =  malloc(2*sizeof(char));
		str[0] = b;
		str[1] = '\0';
	}
	else
	{
		str =  malloc(3*sizeof(char));
		str[0] = a;
		str[1] = b;
		str[2] = '\0';				
	}
	to_print = find_key("numbers_specific.dict", str);
	free(str);
	ft_putstr(to_print);
	free(to_print);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

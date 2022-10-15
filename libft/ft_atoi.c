#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	integer;

	i = 0;
	integer = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		integer = integer * 10 + (str[i] - 48);
		i++;
	}
	return (integer * sign);
}

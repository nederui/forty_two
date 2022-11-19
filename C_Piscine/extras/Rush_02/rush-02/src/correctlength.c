
#include "rush02.h"

char	*correctlength(char *str)
{
	int		length;
	int		bonuszero;
	char	*new_string;
	int		i;

	length = ft_strlen(str);
	bonuszero = 0;
	if (length % 3 != 0)
	{
		bonuszero = 3 - (length % 3);
	}
	length = length + bonuszero;
	new_string = (char *)malloc(sizeof(char) * length + 1);
	i = 0;
	while (i < bonuszero)
		new_string[i++] = '0';
	while (str[i - bonuszero] != '\0')
	{
		new_string[i] = str[i - bonuszero];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}

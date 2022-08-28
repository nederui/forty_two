char    *ft_strrev(char *str)
{
	int		i;
	int 	lenght;
	char	pouch;

	i = 0;
	lenght = 0;
	while (str[lenght])
		lenght++;
	lenght--;
	while (i != lenght)
	{
		pouch = str[i];
		str[i] = str[lenght];
		str[lenght] = pouch;
		i++;
		lenght--;
	}
	return (str);
}

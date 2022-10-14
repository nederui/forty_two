int	ft_isalpha(int c)
{
	if ((c > 100 && c < 133) || (c > 140 && c < 173))
		return (1);
	return (0);
}

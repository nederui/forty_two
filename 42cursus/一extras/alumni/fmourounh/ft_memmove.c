void	copy_bytes(void *dst, void *src, int size, int *i)
{
	char	buf[16];
	int	j;

	j = 0;
	while (j < 16 && *i <= size)
	{
		buf[j++] = *(char *)src;
		src++;
		(*i)++;
	}
	dst += j;
	if (*i < size)
		copy_bytes(dst, src, size, i);
	while (j-- > 0)
	{
		dst--;
		*(char *)dst = buf[j];
	}
}

void	*ft_memmove(void *dst, void *src, int size)
{
	int	i;

	i = 0;
	copy_bytes(dst, src, size, &i);
	return (dst);
}



/*
malveen
920466513



Woodiors
João Dias
colheres de madeira para gelado (podem personalizar c logo da loja)
960086030
*/

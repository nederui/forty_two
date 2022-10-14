#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
{
	size_t  i;
	size_t	i_2;

	i = 0;
	i_2 = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		while (((unsigned char *)dst)[i] == ((unsigned char *)src)[i_2])
			i++;
		((unsigned char *)dst)[i + i_2] = ((unsigned char *)src)[i_2];
		i_2++;
	}
	return(dst);
}

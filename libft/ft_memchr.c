#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (((char *)s)[i] && i < n)
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((char *)s+i);
		i++;	
	}
	return (0);
}

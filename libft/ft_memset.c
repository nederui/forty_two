#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t	i;
	
	i = 0;
	while (i < n)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);	
}

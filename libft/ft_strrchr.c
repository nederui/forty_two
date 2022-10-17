#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	
	i = ft_strlen((char *)s) - 1;
	while (((char *)s)[i])
	{
		if (((char *)s)[i] == (unsigned char)c)
			return ((char *)s+i);
		i--;
	}
	return (0);
}

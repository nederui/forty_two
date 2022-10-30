#include <stdio.h>
#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst > src)
	{
		i = len;
		if (!src)
			return (0);
		while (i-- > 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		return (dst);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

/*
• if our blocks of memory are not going to overlap, we should use
• memcpy() instead, as it may have higher performance;
•
• if we're unsure whether or not the 'dst' & 'src' blocks of memory
• will overlap, then we should use memmove() because it's guaranteed
• to be safe.
*/

int	main(void)
{
	int	source[] = {1,2,3,4,5};
	int	destination[] = {1,2,3,4,5};

	ft_memmove(source, source+2, sizeof(int) * 2);
	memmove(destination, destination+2, sizeof(int) * 2);

	for (int i = 0; i < 5; i++)
		printf("ft_memmove[%d]: %d\n", i, source[i]); 
	for (int i = 0; i < 5; i++)
		printf("memmove[%d]: %d\n", i, destination[i]);
		// printf("ft_memcpy: %s\n", ft_memcpy(source+2, source, sizeof(char) * 8)); 
		// printf("memcpy: %s\n", memcpy(source+2, source, sizeof(char) * 8));
	return 0;
}

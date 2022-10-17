
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (!src)
		return (0);
	while (i-- > 0)
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
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


/*
• the original memcpy() copies 'n' bytes from 'src' to 'dst';
•
• if 'dst' and 'src' overlap, behavior is undefined;
• should that be the case, we must use memmove() instead;
•
• it returns a pointer to its first argument, 'dst';
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

/*
• we use CASTING to avoid getting the error "Incomplete type 'void' is
• not assignable";
•
• as we want to copy from 'src' to 'dst', first we need to tell the computer
• how large is the data we're trying to copy;
•
• we want to copy each byte from src to dst - and we know that a char takes
• 1 byte of space;
•
• so we CAST both 'src' and 'dst' to char, and have a loop copying
• each character from 'src' to 'dst';
*/

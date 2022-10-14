#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t n)
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

int main(void)
{
	char	src[] = "12345";
	char	dst[] = "abcde";
	size_t	n = 3;

	printf("\n\nsource:%s\ndestination:%s\nnr. of bytes:%zu\n", src, dst, n);
	printf("\nreturn:%s\n", ft_memmove(dst, src, n));
	printf("\nreturn:%s\n", memmove(dst, src, n));
	return 0;
}

/*
• if our blocks of memory are not going to overlap, we should use
• memcpy() instead, as it may have higher performance;
•
• if we're unsure whether or not the dst & src blocks of memory will overlap,
• then we should use memmove() because it's guaranteed to be safe.
*/

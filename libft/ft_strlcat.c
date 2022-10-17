#include "libft.h"

#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + ft_strlen((char *)src));
	while (src[i] && i < (dstsize - len_dst - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + ft_strlen((char *)src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t int c;
	size_t int d;

	if (size <= ft_strlen(dest))
		return (size + ft_strlen(src));
	c = ft_strlen(dest);
	d = 0;
	while (src[d] != '\0' && c + 1 < size)
	{
		dest[c] = src[d];
		c++;
		d++;
	}
	dest[c] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[d]));
}

int				main()
{
	char			str0[50];
	char			str1[50];
	char			str2[] = "Concatinating 1";
	unsigned int	tamanho1;
	unsigned int	tamanho2;

	str0[0] = 'O';
	str0[1] = 'l';
	str0[2] = 'a';
	str0[3] = '\0';

	str1[0] = 'O';
	str1[1] = 'l';
	str1[2] = 'a';
	str1[3] = '\0';

	tamanho1 = ft_strlcat(str0, str2, 0);
	tamanho2 = strlcat(str1, str2, 0);
	printf("String final: %s, Tamanho: %d", str0, tamanho1);
	printf("\nString final: %s, Tamanho: %d", str1, tamanho2);
}


// DESCRIPTION
// The strlcpy() and strlcat() functions copy and concatenate strings with the same
// input parameters and output result as snprintf(3).  They are designed to be safer,
// more consistent, and less error prone replacements for the easily misused functions
// strncpy(3) and strncat(3).

// strlcpy() and strlcat() take the full size of the destination buffer and guarantee
// NUL-termination if there is room.  Note that room for the NUL should be included in
// dstsize.

// strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-
// terminating the result if dstsize is not 0.

// strlcat() appends string src to the end of dst.  It will append at most dstsize -
// strlen(dst) - 1 characters.  It will then NUL-terminate, unless dstsize is 0 or the
// original dst string was longer than dstsize (in practice this should not happen as it
// means that either dstsize is incorrect or that dst is not a proper string).

// If the src and dst strings overlap, the behavior is undefined.

// RETURN VALUES
// Besides quibbles over the return type (size_t versus int) and signal handler safety
// (snprintf(3) is not entirely safe on some systems), the following two are equivalent:

// 	n = strlcpy(dst, src, len);
// 	n = snprintf(dst, len, "%s", src);

// Like snprintf(3), the strlcpy() and strlcat() functions return the total length of
// the string they tried to create.  For strlcpy() that means the length of src.  For
// strlcat() that means the initial length of dst plus the length of src.

// If the return value is >= dstsize, the output string has been truncated.  It is the
// caller's responsibility to handle this.
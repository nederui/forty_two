#include "libft.h"

void	*calloc(size_t nmemb, size_t size)
{
	char	*array;

	array = (char *) malloc(nmemb * size);
	if (array)
		ft_bzero(array, nmemb * size);
	return (array);
}

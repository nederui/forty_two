#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len_set;

	if (!s1 || !set)
		return (0);
	while (s1 == set)
		s1++;
	i = ft_strlen(s1) - 1;
	len_set = ft_strlen(set) - 1;
	while (s1[i] == set[len_set])
		i--;
		len_set--;
	return(ft_substr(s1, 0, i + 1));
}



Allocates (with malloc(3)) and returns a copy of
's1' with the characters specified in 'set' removed
from the beginning and the end of the string.
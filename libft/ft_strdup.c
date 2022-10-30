#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*array;
	size_t	len_s1;

	len_s1 = ft_strlen((char *)s1);
	array = (char *) malloc(len_s1 + 1);
	if (array)
		ft_memcpy(array, s1, len_s1);
	array[len_s1] = '\0';
	return (array);
}



int	main(void)
{
	char	*str;
	char	*str_copy;

	str = "Test string.";
	str_copy = ft_strdup(str);
	if (strcmp(str, str_copy) != 0)
		printf("KO, string is not the same.\n");
	else
		printf("OK.\n");
	free(str_copy);
	str = "";
	str_copy = ft_strdup(str);
	if (strcmp(str, str_copy) != 0)
		printf("KO, string is not the same.\n");
	else
		printf("OK.\n");
	free(str_copy);
	str = "gado";
	str_copy = ft_strdup(str);
	if (strcmp(str, str_copy) != 0)
		printf("KO, string is not the same.\n");
	else
		printf("OK.\n\n\n");
	printf("%d\n", str_copy[ft_strlen(str_copy)]);
	printf("%s\n", str_copy);
	free(str_copy);
	printf("%s\n", str_copy);
	return (0);
}



// char *
// strndup(const char *s1, size_t n);

// DESCRIPTION
// The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to
// the function free(3).

// If insufficient memory is available, NULL is returned and errno is set to ENOMEM.

// The strndup() function copies at most n characters from the string s1 always NUL terminating the copied string.


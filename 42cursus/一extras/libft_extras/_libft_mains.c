#include <stdio.h>
#include <string.h>

int main(void)
{
	int	source[] = {1,2,3,4,5};
	int	destination[] = {1,2,3,4,5};

	ft_memmove(source+2, source, sizeof(int) * 3);
	memmove(destination+2, destination, sizeof(int) * 3);

	for (int i = 0; i < 5; i++)
		printf("ft_memmove[%d]: %d\n", i, source[i]); 
	for (int i = 0; i < 5; i++)
		printf("memmove[%d]: %d\n", i, destination[i]);
		// printf("ft_memcpy: %s\n", ft_memcpy(source+2, source, sizeof(char) * 8)); 
		// printf("memcpy: %s\n", memcpy(source+2, source, sizeof(char) * 8));
	return 0;
}


int main(void)
{
	int	source[] = {1,2,3,4,5};
	int	destination[] = {1,2,3,4,5};

	ft_bzero(source, sizeof(int) * 3);
	bzero(destination, sizeof(int) * 3);

	for (int i = 0; i < 5; i++)
		printf("ft_bzero[%d]: %d\n", i, source[i]); 
	for (int i = 0; i < 5; i++)
		printf("bzero[%d]: %d\n", i, destination[i]); 
	return 0;
}


int main(void)
{
	char	s[] = "eabcdefghij";
	int	c = 101;

	printf("%s\n", strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
		printf("%s\n", strrchr(s, c));
	printf("%s\n", ft_strrchr(s, c));
	return 0;
}


int		main(void)
{
	char str[] = "123123343456";
	char to_find[] = "231";
	size_t	n = 4;

	printf("-----\nstr = %s\nto_find = %s\nn = %zu\n", str, to_find, n);
	printf("strnstr:%s\n", strnstr(str, to_find, n));
	printf("ft_strnstr:%s\n", ft_strnstr(str, to_find, n));

	return (0);
}

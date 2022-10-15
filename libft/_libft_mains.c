
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
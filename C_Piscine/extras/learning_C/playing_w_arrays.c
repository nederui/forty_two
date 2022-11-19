#include <stdio.h>
#include <unistd.h>
#include <string.h>

void	ft_rev_int_tab(int *tab, int size)
{
	
}

int	main(void)
{
	int	size;
	int	i;

	int	array[] = {0, 1, 3, 6, 9, 12};
	size = 6;
	i = 0;
	while (i < size)
	{
		printf("%d ", array[i]);
		i++;
	}
	return (0);
}
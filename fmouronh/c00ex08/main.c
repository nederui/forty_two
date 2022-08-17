#include <stdio.h>

void ft_print_combn(int n);

int main()
{
	int usrin;

	printf("Provide integer: ");
	scanf("%d,",&usrin);

	ft_print_combn(usrin);

	printf("\n");
	return 0;
}

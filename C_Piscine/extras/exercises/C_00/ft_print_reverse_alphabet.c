#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
	char l = 122;
	
	while( l > 96)
	{
		write(1, &l, 1);
		l--;
	}
}

int main()
{
	ft_print_reverse_alphabet();
}

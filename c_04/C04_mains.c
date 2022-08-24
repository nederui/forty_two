#include <stdio.h>


////////////////////////////////////////////////////////////
//ex00//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// int		ft_strlen(char *str);

// int		main (void)
// {
// 	char str[] = "Halloo";
// 	char *p_str;

// 	p_str = str;

// 	int count = ft_strlen(p_str);
	
// 	printf("%d\n", count );
// }


////////////////////////////////////////////////////////////
//ex01//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// void	ft_putstr(char *str);

// int		main(void)
// {
// 	char str[] = "Hello, world!";
// 	char *p_str;

// 	p_str = str;
// 	ft_putstr(p_str);
// }


////////////////////////////////////////////////////////////
//ex02//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// void	ft_putnbr(int n);

// int		main(void)
// {
//     printf(" (printed) should be 1");
//     ft_putnbr(1);
//     printf("\n (printed) should be 0");
//     ft_putnbr(0);
//     printf("\n (printed) should be -1");
//     ft_putnbr(-1);
//     printf("\n (printed) should be 2147483647");
//     ft_putnbr(2147483647);
//     printf("\n (printed) should be -21474836478");
//     ft_putnbr(-2147483648);
//     printf("\n");
//     return (0);
// }


////////////////////////////////////////////////////////////
//ex03//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// int		ft_atoi(char *str);

// int		main(void)
// {
// 	printf("%d\n", ft_atoi("      	---+--+2147--+-ab567"));

// }


////////////////////////////////////////////////////////////
//ex04//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


void	ft_putnbr_base(int nbr, char *base);

int main(void)
{
	char base[] = "10";
	unsigned long c;

	c = 0;
	while (c < (sizeof(base) - 1))
	{
		ft_putnbr_base(c, base);
		c++;
	}
	c = 0;
	while (c < (sizeof(base) - 1))
	{
		ft_putnbr_base(c, base);
		c++;
	}
	printf("\n");
	ft_putnbr_base(-1, base);
	printf("\n");
}


////////////////////////////////////////////////////////////
//ex05//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// int ft_atoi_base(char *str, char *base);

// int main(void)
// {
// 	printf("%d\n", ft_atoi_base("  -+-042 + 893 --", "0123456789"));
// }
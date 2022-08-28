//
// #include <unistd.h>
//
// void ft_putchar()
// {
//	char c = 'a';
//	write(1, &c, 1);
// 
//	return (0);
// }
// 
// int main(void)
// {
// 	
// 	ft_putchar();
// 
// 	return (0);
// 
// }
//

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);

}

int main()
{
ft_putchar('c');
return (0);
}

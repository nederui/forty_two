// #include <unistd.h>
// 
// int main()
// {
// 	write(1, "Hello nuno\n", 11);
// 
// 	return (0);
// }


#include <unistd.h>

void ft_putchar()
{
	char c = 'a';
	write(1, &c, 1);

//	return (0);
}

int main(void)
{
	
	ft_putchar();

	return (0);

}

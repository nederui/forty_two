#include <stdio.h>
#include <unistd.h>
#include <string.h>

void    ft_putchar(char ptr)
{
    write(1, &ptr, 1);
}

void    ft_putnbr_fd(int ptr)
{
	if (ptr == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr_fd(147483648);
	}
	if (ptr < 0 && ptr != -2147483648)
	{
		ft_putchar('-');
		ptr = -ptr;
	}
	if (ptr > 9)
	{
		ft_putnbr_fd(ptr / 10);
		ft_putnbr_fd(ptr % 10);
	}
	else
	{
		if (ptr != -2147483648)
		{
			ft_putchar(ptr + 48);
		}
	}
}

void    ftputaddr(void *ptr)
{
    printf("%p\n", (void *) ptr);
}

int main(void)
{
    int tab[10];

    tab[3] = 42;
    ftputaddr(tab + 1);
    ft_putchar(' ');
    ft_putnbr_fd(tab[3]);
    ft_putchar('\n');
    return (0);
}
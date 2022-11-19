#include <unistd.h>

void    ft_putchar(char c)
{
    int number;

    number = c / 10 + 48;
    if (number != 48)
        write(1, &number, 1);
    number = c % 10 + 48;
    write (1, &number, 1);
    write(1, "\n", 1);
}

int main()
{
    int number;

    number = 1;
    while (number < 100)
    {
        if (number % 3 == 0 && number % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (number % 3 == 0)
            write(1, "fizz\n", 5);
        else if (number % 5 == 0)
            write(1, "buzz\n", 5);
        else
            ft_putchar(number);
        number++;
    }
    write(1, "buzz\n", 9);
    return (0);
}

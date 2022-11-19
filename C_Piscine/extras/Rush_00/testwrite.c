#include <unistd.h>

void ft_put_char(char c)
        {
            write(1, &c, 1);
        }

void    rush()
    {
        ft_put_char('A');
    }
    
    int main()
    {
        rush();
        return(0);
    }
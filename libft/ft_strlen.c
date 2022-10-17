#include "libft.h"

#include <stdio.h>

size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(void)
{
    char str[] = "12345";
    printf("%zu", ft_strlen(str));
    return 0;
}

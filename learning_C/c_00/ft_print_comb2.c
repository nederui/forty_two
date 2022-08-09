#include <unistd.h>

void	ft_print_comb2(void)
{
	char	a = 48;
	char	b = a +1;
	char	c = 48;
//	char	d = c +1;

	while (c < 58)
	{
		write(1, &a, 1);
		write(1, &b, 1);
		write(1, &c, 1);
		if (a != 55)
		{
			write(1, ", ", 2);
		}
		c++;
		if (c == 58)
		{
			c = b;
			b++;
			if (b == 57)
			{
				b = a;
				a++;
				while (b <= a)
				{
					b++;
				}
			}
			while (c <= b)
			{
				c++;
			}	
		}
	}
}

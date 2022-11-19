#include <unistd.h>

void ft_is_negative(int n)			// a void fn w/ an inter var assigned
{
	if(n >= 0)
	{								// if the inter entered as a parameter on main ranges between [0 - 255]
		write(1,"P", 1);	// write 'P'
	}
	
	else
	{								// if it ranges between [-128 to -1]
		write(1,"N", 1);			// write 'N'
	}
}

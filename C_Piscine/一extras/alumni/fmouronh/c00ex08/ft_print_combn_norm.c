#include <unistd.h>

void	ft_putnbr_fd(int nb)
{
	int	snb;
	int	nbr;
	int	printable;
	int	rem;
	int	dec_plc;
	int	count;
	
	snb = nb;
	nbr = snb;
	dec_plc = 1;
	rem = 0;
	count = 0;
	if (nbr < 0)
	{
		printable = '-';
		nbr = snb;
		snb = 0 - nb;
		write(1, &printable, 1);
	}
	if (nbr == 0)
	{
		printable = '0';
		write(1, &printable, 1);
	}
	else
	{
		while (nbr != 0)
		{
			while (nbr != 0)
			{
				if (nbr / 10 == 0)
				{
					printable = nbr % 10 + 48;
					write(1, &printable, 1);
					while (count > 0)
					{
						dec_plc = dec_plc * 10;
						count--;
					}
					rem = rem + ((printable - 48) * dec_plc);
				}
				nbr = nbr / 10;
				count++;
			}
			nbr = snb - rem;
			count = 0;
			dec_plc = 1;
		}
	}
}

void	ft_print_combn(int n)
{
	int	comb[9];
	int	i;
	int	done;
	char	sep;

	sep [2] = ", ";
	i = 0;
	while (i < n)
	{
		comb[i] = i;
		i++;
	}
	i = 0;
	while (i < n)
	{
		ft_putnbr_fd(comb[i]);
		i++;
	}
	done = 0;
	while (done != 1)
	{
		if (comb[n -1] < 9)
		{
			comb[n -1]++;
		}
		else if (comb[n -1] == 9)
		{
			if (n == 1)
			{
				done = 1;
				break ;
			}
			i = n -1;
			while (i > 0)
			{
				if (comb[i] - comb[i - 1] > 1)
				{
					comb[i - 1]++;
					comb[i] = comb[i - 1] + 1;
				}
				i--;
			}
		}
		write(1, &sep, 2);
		i = 0;
		while (i < n)
		{
			ft_putnbr_fd(comb[i]);
			i++;
		}
		if (comb[n -1] == 9)
		{
			i = 0;
			while (i < n -1)
			{
				if (comb [i +1] - comb [i] != 1)
				{
					done = 0;
					break ;
				}
				else
				{
					done = 1;
				}
				i++;
			}
		}
	}
}

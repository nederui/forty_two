#include <unistd.h>

void ft_putnbr_fd(int nb)
{
	int snb = nb;
	int nbr = snb;
	int printable;

	int rem = 0;		//nbr*dec_plc, to be removed from nb at each iteration
	int dec_plc = 1;
	int count = 0;		//to loop through nbr & find total dec places

	//negt-proofing
	if(nbr<0)
	{
		printable='-';
		nbr = snb = 0-nb;
		write(1,&printable,1);
	}

	//zero-proofing;
	if(nbr == 0)
	{
		printable = '0';
		write(1,&printable,1);
	}
	else
	{
		while(nbr!=0)
		{
			while(nbr!=0)
			{
				if(nbr/10 == 0)
				{
					printable = nbr%10+48;
					write(1,&printable,1);

					while(count>0)
					{
						dec_plc = dec_plc*10;
						count--;
					}
					rem = rem + ((printable-48)*dec_plc);
				}
				nbr = nbr/10;
				count++;
			}
			nbr = snb-rem;
			count = 0;
			dec_plc = 1;
		}
	}
}

void ft_print_combn(int n)
{
	int comb[9];			// = n split into array
	int i;					// to use in loops
	int done;				// to keep main loop in check
	char sep[2] = ", ";		// separator for output

	// generate array at {0,1,2,..,n-1}
	i = 0;
	while(i < n)
	{
		comb[i] = i;
		i++;
	}

	// print first iteration
	i = 0;
	while(i < n)
	{
		ft_putnbr_fd(comb[i]);
		i++;
	}

	//start main loop
	done = 0;
	while(done != 1)
	{
		// keep incrementing the last index until it's 9
		if(comb[n-1] < 9)
		{
			comb[n-1]++;
		}
		else if(comb[n-1] == 9)
		{
			// 1-proofing
			if(n == 1)
			{
				done = 1;
				break;
			}
			// find elements that don't match the criteria & fix it
			i = n-1;
			while(i > 0)
			{
				// when condition is met, index [-2] is incremented and index [-1] is set at index[-2]+1
				if(comb[i] - comb[i - 1] > 1)
				{
					comb[i - 1]++;
					comb[i] = comb[i - 1] + 1;
				}
				i--;
			}
		}

		//print the array
		write(1, &sep, 2);
		i = 0;
		while(i < n)
		{
			ft_putnbr_fd(comb[i]);
			i++;
		}

		// when last index is 9,
		// check that conditions for last loop are met
		if(comb[n-1] == 9)
		{
			i = 0;
			while(i < n-1)
			{
				// more combinations to print, keep done at 0 to continue main loop
				if(comb[i+1] - comb[i] != 1)
				{
					done = 0;
					break;
				}
				// continue comparing values until end of array;
				// if all conform to norm val[1] - val[0] == 1,
				// then set done to 1 to break main loop
				else
				{
					done = 1;
				}
				i++;
			}

		}

	}
}

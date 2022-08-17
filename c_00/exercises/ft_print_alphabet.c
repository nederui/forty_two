#include <unistd.h>				// telling the computer in which library 
								// he should look for our non-functions
void ft_print_alphabet(void)	// defining our (void) function
{
	char l = 97;				// defining variable "l" & setting it to "97"
								// (97 = "a" in decimal set of the ascii table)

	while(l < 123)				// calling a while loop
	{							// while var "l" is lower than "123" (ascii: "z")
		write(1, &l, 1);		// &reads the value for "l", stored in the memory
	l++;						// increments var "l" by 1
	}	
}

//
//

int main()						// calling out our main fn
{
	ft_print_alphabet();		// calling it inside main()

	return (0);					// asking for a return (?)
}

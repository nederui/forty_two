/*
The toupper() function converts a lower-case letter to the corresponding upper-case
letter.  The argument must be representable as an unsigned char or the value of EOF.
*/

int ft_toupper(int c)
{
	if (c > 96 && c < 123)
        c -= 32;
	return (c);
}

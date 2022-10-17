/*
The tolower() function converts an upper-case letter to the corresponding lower-case letter.
The argument must be representable as an unsigned char or the value of EOF.
*/

int ft_tolower(int c)
{
	if (c > 64 && c < 91)
        c += 32;
	return (c);
}

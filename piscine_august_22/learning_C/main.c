#include <stdio.h>

int main()
{
	int a;
	int b;

	a = 42;
	b = 89;
	printf("hello %d world %d\n", a, b);
	a = b;
	a = 22;
        printf("hello %d world %d\n", a, b);
	b = a;
        a = 12;
        printf("hello %d world %d\n", a, b);
}

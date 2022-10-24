SYNOPSIS
#include <string.h>

char *
strdup(const char *s1);

char *
strndup(const char *s1, size_t n);

DESCRIPTION
The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to
the function free(3).

If insufficient memory is available, NULL is returned and errno is set to ENOMEM.

The strndup() function copies at most n characters from the string s1 always NUL terminating the copied string.
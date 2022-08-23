
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////
//ex00//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// int		ft_strcmp(char *s1, char *s2);

// int		main()
// {
// 	char s1[] = "0000";
// 	char s2[] = "00001234";
// 	char s3[] = "Test";

// 	printf("s12: %d, s21: %d, s13: %d, s31: %d, s23: %d, s32: %d", ft_strcmp(s1, s2), ft_strcmp(s2, s1), ft_strcmp(s1, s3), ft_strcmp(s3, s1), ft_strcmp(s2, s3), ft_strcmp(s3, s2));
// 	printf("\n\ns12: %d, s21: %d, s13: %d, s31: %d, s23: %d, s32: %d", strcmp(s1, s2), strcmp(s2, s1), strcmp(s1, s3), strcmp(s3, s1), strcmp(s2, s3), strcmp(s3, s2));
// }


////////////////////////////////////////////////////////////
//ex01//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// int		ft_strncmp(char *s1, char *s2, unsigned int n);

// int		main()
// {
// 	char s1[] = "Giberish";
// 	char s2[] = "Comparisson Test";
// 	char s3[] = "Test";
// 	unsigned int n;
// 	n = 0;

// 	printf("s12: %d, s21: %d, s13: %d, s31: %d, s23: %d, s32: %d", ft_strncmp(s1, s2, n), ft_strncmp(s2, s1, n), ft_strncmp(s1, s3, n), ft_strncmp(s3, s1, n), ft_strncmp(s2, s3, n), ft_strncmp(s3, s2, n));
// 	printf("\n\ns12: %d, s21: %d, s13: %d, s31: %d, s23: %d, s32: %d", strncmp(s1, s2, n), strncmp(s2, s1, n), strncmp(s1, s3, n), strncmp(s3, s1, n), strncmp(s2, s3, n), strncmp(s3, s2, n));
// }


////////////////////////////////////////////////////////////
//ex02//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// char	*ft_strcat(char *dest, char *src);

// int		main(void)
// {
// 	char dest[20] = "Hello";
// 	char src[] = ", world!";

// 	printf("-----\ndest = %s\nsrc = %s\n", dest, src);
// 	ft_strcat(dest, src);
// 	printf("result = %s\n-----\n", dest);

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex03//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// char *ft_strncat(char *dest, char *src, unsigned int nb);

// int		main(void)
// {
// 	char dest[20] = "123";
// 	char src[] = "4567890";
// 	unsigned int nb = 1;

// 	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n", dest, src, nb);
// 	ft_strncat(dest, src, nb);
// 	printf("result = %s\n-----\n", dest);

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex04//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// char *ft_strstr(char *str, char *to_find);

// int		main(void)
// {
// 	char str[] = "123456";
// 	char to_find[] = "654";

// 	printf("-----\nstr = %s\nto_find = %s\n", str, to_find);
// 	printf("%s\n", ft_strstr(str, to_find));
// 	printf("%s\n", strstr(str, to_find));

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex05//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

// int		main(void)
// {
// 	char dest[20] = "123";
// 	char src[] = "4567890";
// 	unsigned int size = 6;
// 	unsigned int result;

// 	printf("-----\ndest = %s\nsrc = %s\nnb = %d\n\n", dest, src, size);
// 	result = strlcat(dest, src, size);
// 	printf("dest (cat) = %s\nresult = %d\n-----\n", dest, result);

// 	return (0);
// }






























// unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

// int				main()
// {
// 	char			str0[50];
// 	char			str1[50];
// 	char			str2[] = "Concatinating 1";
// 	unsigned int	tamanho1;
// 	unsigned int	tamanho2;

// 	str0[0] = 'O';
// 	str0[1] = 'l';
// 	str0[2] = 'a';
// 	str0[3] = '\0';

// 	str1[0] = 'O';
// 	str1[1] = 'l';
// 	str1[2] = 'a';
// 	str1[3] = '\0';

// 	tamanho1 = ft_strlcat(str0, str2, 0);
// 	tamanho2 = strlcat(str1, str2, 0);
// 	printf("String final: %s, Tamanho: %d", str0, tamanho1);
// 	printf("\nString final: %s, Tamanho: %d", str1, tamanho2);
// }





/////////////////////////////////////////////////////////

// int	ft_strcmp(char *s1, char *s2);

// int	main(void)
// {
// 	char *s1;
// 	char *s2;
// 	char *s3;
// 	char *s4;
// 	char s5[] = {'a', 'b', 'c', -10, -20, '\0'};
// 	char *s6;
// 	char *s7;

// 	s1 = calloc(10, sizeof(char));
// 	s2 = calloc(8, sizeof(char));
// 	s3 = calloc(10, sizeof(char));
// 	s4 = calloc(10, sizeof(char));
// 	s6 = calloc(10, sizeof(char));
// 	s7 = calloc(1, sizeof(char));
// 	s1 = "abcdefghi";
// 	s2 = "abcdefg";
// 	s3 = "abcdEfghi";
// 	s4 = "ab0defghi";
// 	s6 = "abcdefghi"; // s6 is the same of s1
// 	s7 = "";
// 	printf("s1: %s, s2: %s, s3: %s, s4: %s, s5: %s, s6: %s, s7: %s\n", s1, s2, s3, s4, s5, s6, s7);
// 	printf("ft_strcmp(s1, s2)\t= %d\noriginal strcmp(s1, s2)\t= %d\n------------------------------\n", ft_strcmp(s1, s2), strcmp(s1, s2));
// 	printf("ft_strcmp(s1, s3)\t= %d\noriginal strcmp(s1, s3)\t= %d\n------------------------------\n", ft_strcmp(s1, s3), strcmp(s1, s3));
// 	printf("ft_strcmp(s1, s4)\t= %d\noriginal strcmp(s1, s4)\t= %d\n------------------------------\n", ft_strcmp(s1, s4), strcmp(s1, s4));
// 	printf("ft_strcmp(s1, s5)\t= %d\noriginal strcmp(s1, s5)\t= %d\n------------------------------\n", ft_strcmp(s1, s5), strcmp(s1, s5));
// 	printf("ft_strcmp(s1, s6)\t= %d\noriginal strcmp(s1, s6)\t= %d\n------------------------------\n", ft_strcmp(s1, s6), strcmp(s1, s6));
// 	printf("ft_strcmp(s1, s7)\t= %d\noriginal strcmp(s1, s7)\t= %d\n------------------------------\n", ft_strcmp(s1, s7), strcmp(s1, s7));
// 	return(0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strncmp(char *s1, char *s2, unsigned int n);

void	ft_strncmp_test(char *s1, char *s2, unsigned int n)
{
	int res;
	int ft_res;

	res = strncmp(s1, s2, n);
	ft_res = ft_strncmp(s1, s2, n);
	if (res != ft_res)
		printf("> KO, expected: %d, got: %d\n", res, ft_res);
	else
		printf("> OK, result: %d\n", ft_res);
}

int		main(void)
{
	char	*s1 = "abcdefghi";
	char	*s2 = "abcdEfghi";
	char	s3[] = {'a', 'b', -23, 'd', 'e', 'f', 'g', 'h', 'i', '\0'};
	char	*s4 = "abcdefghi";
	char	*s5 = "abcd";
	char	*s6 = "abcdefghijklmn";
	char	*s7 = "";

	int		offset;

	offset = 0;
	printf("[1] Testing strings \"%s\" and \"%s\"\n", s1, s2);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s2, offset);
		offset++;
	}
	offset = 0;
	printf("[2] Testing strings \"%s\" and \"%s\"\n", s1, s3);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s3, offset);
		offset++;
	}
	offset = 0;
	printf("[3] Testing strings \"%s\" and \"%s\"\n", s2, s3);
	while (offset < 10)
	{
		ft_strncmp_test(s2, s3, offset);
		offset++;
	}
	offset = 0;		// Comparing equal strings. Should return 0.
	printf("[4] Testing strings \"%s\" and \"%s\" (same strings)\n", s1, s4);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s4, offset);
		offset++;
	}
	offset = 0;		// Comparing with a shorter string (s5 lenght 5).
	printf("[5] Testing strings \"%s\" and \"%s\"\n", s1, s5);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s5, offset);
		offset++;
	}
	offset = 0;		// Comparing with a longer string (s6 lenght 15).
	printf("[6] Testing strings \"%s\" and \"%s\"\n", s1, s6);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s6, offset);
		offset++;
	}
	offset = 0;		// Comparing with an empty string (s7).
	printf("[7] Testing strings \"%s\" and \"%s\"\n", s1, s7);
	while (offset < 10)
	{
		ft_strncmp_test(s1, s7, offset);
		offset++;
	}
	return (0);
}
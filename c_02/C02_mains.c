#include <string.h>
#include <stdio.h>

////////////////////////////////////////////////////////////
//ex00//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// char	*ft_strcpy(char *dest, char *src);

// int		main(void)
// {
// 	char source[] = "Source string.";
// 	char destin[] = "Destination string.";
// 	char *dest;

// 	printf("BEFORE\n\tsrc: %s\n\tdes: %s\n", source, destin);

//     dest = ft_strcpy(destin, source);

// 	printf("AFTER\n\tsrc: %s\n\tdes: %s\n", source, dest);
// 	return (0);
// }



////////////////////////////////////////////////////////////
//ex01//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// char	*ft_strncpy(char *dest, char *src, unsigned int n);

// int		main(void)
// {
// 	char src[] = "Source string.";
// 	char dest[] = "string.";
// 	unsigned int n;

// 	n = 2;

// 	printf("BEFORE\n\tsrc: %s\n\tdes: %s\n", src, dest);

//     ft_strncpy(dest, src, n);

// 	printf("AFTER\n\tsrc: %s\n\tdes: %s\n", src, dest);
// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex02//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// int		ft_str_is_alpha(char *str);

// int		main(void)
// {
// 	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
// 	char *p_alp;
// 	p_alp = alpha;

// 	char special[] = "ABC abc áéíóú àèìòù âêîôû äëïöü \'\"(){}[]!?@#$&* wxyz WXYZ";
// 	char *p_spe;
// 	p_spe = special;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("-----\n1 = String contains only alphabetical chars\n0 = String doesn't contain only alphabetical chars\n\n");
// 	printf("%s = %d\n", alpha, ft_str_is_alpha(p_alp));
// 	printf("%s = %d\n", special, ft_str_is_alpha(p_spe));
// 	printf("Empty = %d\n-----\n", ft_str_is_alpha(p_emp));

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex03//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// int		ft_str_is_numeric(char *str);

// int		main(void)
// {
// 	char numeric[] = "0123456789";
// 	char *p_num;
// 	p_num = numeric;

// 	char special[] = "0123456789_";
// 	char *p_spe;
// 	p_spe = special;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("-----\n1 = String contains only numerical chars\n0 = String doesn't contain only numerical chars\n\n");
// 	printf("%s = %d\n", numeric, ft_str_is_numeric(p_num));
// 	printf("%s = %d\n", special, ft_str_is_numeric(p_spe));
// 	printf("Empty = %d\n-----\n", ft_str_is_numeric(p_emp));

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex04//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// int		ft_str_is_lowercase(char *str);

// int		main(void)
// {
// 	char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
// 	char *p_lwr;
// 	p_lwr = lowercase;

// 	char special[] = "abcdefghijklmnopqrstuvwxyz_";
// 	char *p_spe;
// 	p_spe = special;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("-----\n1 = String contains only lowercase chars\n0 = String doesn't contain only lowercase chars\n\n");
// 	printf("%s = %d\n", lowercase, ft_str_is_lowercase(p_lwr));
// 	printf("%s = %d\n", special, ft_str_is_lowercase(p_spe));
// 	printf("Empty = %d\n-----\n", ft_str_is_lowercase(p_emp));

// 	return (0);
// }

////////////////////////////////////////////////////////////
//ex05//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// int		ft_str_is_uppercase(char *str);

// int		main(void)
// {
// 	char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	char *p_upr;
// 	p_upr = uppercase;

// 	char special[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_";
// 	char *p_spe;
// 	p_spe = special;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("-----\n1 = String contains only uppercase chars\n0 = String doesn't contain only uppercase chars\n\n");
// 	printf("%s = %d\n", uppercase, ft_str_is_uppercase(p_upr));
// 	printf("%s = %d\n", special, ft_str_is_uppercase(p_spe));
// 	printf("Empty = %d\n-----\n", ft_str_is_uppercase(p_emp));

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex06//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

// int		ft_str_is_printable(char *str);

// int		main(void)
// {
// 	char string[] = "Normal characters string";
// 	char *p_str;
// 	p_str = string;

// 	char unpr[] = "Unprintables: \t (tab), \a (?)";
// 	char *p_unp;
// 	p_unp = unpr;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("-----\n1 = Contains only printable characters\n0 = Contains unprintable characters\n\n");
// 	printf("%s = %d\n", string, ft_str_is_printable(p_str));
// 	printf("%s = %d\n", unpr, ft_str_is_printable(p_unp));
// 	printf("Empty = %d\n-----\n", ft_str_is_printable(p_emp));

// 	return (0);
// }


////////////////////////////////////////////////////////////
//ex07//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// char	*ft_strupcase(char *str);

// int		main(void)
// {
// 	char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
// 	char *p_lwr;
// 	p_lwr = lowercase;
	
// 	char allcases[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	char *p_all;
// 	p_all = allcases;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("\n-----\n%s = ", lowercase);
// 	printf("%s\n", ft_strupcase(p_lwr));
// 	printf("%s = ", allcases);
// 	printf("%s\n", ft_strupcase(p_all));
// 	printf("Empty = %s\n-----\n", ft_strupcase(p_emp));

// }


////////////////////////////////////////////////////////////
//ex08//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// char	*ft_strlowcase(char *str);

// int		main(void)
// {
// 	char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	char *upr;
// 	upr = uppercase;
	
// 	char allcases[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
// 	char *p_all;
// 	p_all = allcases;

// 	char empty[] = "";
// 	char *p_emp;
// 	p_emp = empty;

// 	printf("\n-----\n%s = ", uppercase);
// 	printf("%s\n", ft_strlowcase(upr));
// 	printf("%s = ", allcases);
// 	printf("%s\n", ft_strlowcase(p_all));
// 	printf("Empty = %s\n-----\n", ft_strlowcase(p_emp));

// }


////////////////////////////////////////////////////////////
//ex09//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


char	*ft_strcapitalize(char *str);

int		main(void)
{
	char str1[] = "^uIv#= =9Hf~2y@F3A)FTzBgF";
	
	char str2[] = " tsR1|vn_WE}   7X6{Vm2vQf(rG}qdnT`1,qH+n";

	char empty[] = "";

	printf("\n-----\nBEF = %s", str1);
	printf("\nAFT = %s\n", ft_strcapitalize(str1));
	printf("\nBEF = %s", str2);
	printf("\nAFt = %s\n", ft_strcapitalize(str2));
	printf("\nEmpty = %s\n-----\n", ft_strcapitalize(empty));

}


////////////////////////////////////////////////////////////
//ex10//////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


// unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

// int		main(void)
// {
// 	char src[] = "Source";
// 	char dest[] = "Destination";
// 	unsigned int n;

// 	n = 0;

// 	printf("BEFORE\n\tsrc: %s\n\tdes: %s\n\tsize: %d\n", src, dest, n);

//     n = ft_strlcpy(dest, src, n);

// 	printf("AFTER\n\tsrc: %s\n\tdes: %s\n\tsize: %d", src, dest, n);
// 	return (0);
// }
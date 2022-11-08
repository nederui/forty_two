/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:41:25 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:41:25 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*newstring;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
		len--;
	newstring = ft_substr((char *)s1, 0, len + 1);
	return (newstring);
}

// int	strleng(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (*str != '\0')
// 	{
// 		i++;
// 		str++;
// 	}
// 	return (i);
// }

// char    *strrev(char *str)
// {
//     int     i;
//     int     s;
//     char    c;
//     char    *res;

//     s = strleng(str);
//     res = malloc (s + 1);
//     i = 0;
//     while (i <= s / 2)
//     {
//         c = str[i];
//         res[i] = str[s - 1 - i];
//         res[s - 1 - i] = c;
//         i++;
//     }
//     res[i * 2] = '\0';
//     return (res);
// }

// char *trim(char const *s1, char const *set)
// {
//     int     i;
//     int     j;
//     char    *r;

//     i = 0;
//     while (s1[i] != '\0')
//     {
//         j = 0;
//         while (set[j] != '\0')
//         {
//             if (s1[i] == set[j])
//             {
//                 i++;
//                 break;
//             }
//             j++;
//         }
//         if (set[j] == '\0')
//             break;
//     }
//     r = malloc(strleng((char *)s1) - i + 1);
//     j = 0;
//     while (s1[i] !=  '\0')
//     {
//         r[j++] = s1[i++];
//     }
//     r[j] = '\0';
//     return(r);
// }

// char *ft_strtrim(char const *s1, char const *set)
// {
//     char *r;

//     r = trim(s1, set);
//     r = strrev(r);
//     r = trim((char const *)r, set);
//     r = strrev(r);
//     return (r);
// }

// int main(void)
// {
//     printf("%s\n",ft_strtrim("Hello guys how are you", " leHYuo"));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:17:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 06:29:22 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*string;
	size_t		len_s1;
	size_t		len_s2;

	if (s1 && s2)
	{
		len_s1 = ft_strlen(s1);
		len_s2 = ft_strlen(s2);
		string = (char *) malloc(len_s1 + len_s1 + 1);
		if (string)
		{
			ft_memcpy(string, (char *)s1, len_s1);
			ft_memcpy(string + len_s1, (char *)s2, len_s2);
			string[len_s1 + len_s2] = '\0';
		}
	}
	return (string);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char		*string;
// 	size_t		i;
// 	size_t		i_s2;

// 	if (s1 && s2)
// 	{
// 		string = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
// 		if (string)
// 		{
// 			i = 0;
// 			i_s2 = i;
// 			while (i < ft_strlen(s1))
// 			{
// 				string[i] = s1[i];
// 				i++;
// 			}
// 			while (i_s2 < ft_strlen(s2))
// 			{
// 				string[i + i_s2] = s2[i_s2];
// 				i_s2++;
// 			}
// 			string[i + i_s2] = '\0';
// 		}
// 	}
// 	return (string);
// }

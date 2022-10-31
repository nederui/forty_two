/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:17:44 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/30 14:17:54 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		i;
	int		i_s2;

	string = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (string && s1 && s2)
		i = 0;
		i_s2 = i;
		while (s1)
		{
			string[i] = s1[i];
			i++;
		}
		while (s2)
		{
			string[i + i_s2] = s2[i_s2];
			i_s2++;
		}
		string[i + i_s2] = '\0';
	else
		return (0);
	return(string);
}

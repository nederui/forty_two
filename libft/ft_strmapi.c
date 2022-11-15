/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:18:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/14 20:44:37 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;

	i = 0;
	if (!s)
		return (NULL);
	string = (char *) malloc(ft_strlen(s) + 1);
	if (string)
	{
		if (s && f)
		{	
			while (s[i])
			{
				string[i] = f(i, s[i]);
				i++;
			}
			string[i] = '\0';
		}
	}
	return (string);
}

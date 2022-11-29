/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 00:22:45 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/23 00:40:09 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	if (!s)
		return (NULL);
	res = (unsigned char *)malloc(ft_strlen(s) + 1);
	if (res)
	{
		if (s && f)
		{
			while (s[i])
			{
				res[i] = f(i, s[i]);
				i++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}

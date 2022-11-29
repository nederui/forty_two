/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 19:38:35 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/22 20:30:23 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len;
	size_t			i;
	size_t			i2;
	unsigned char	*res;

	len = ft_strlen(s1) + ft_strlen(s2);
	res = (unsigned char *)malloc(len + 1);
	if (!s1 || !s2)
		return (NULL);
	if (res)
	{
		i = -1;
		i2 = i;
		while (++i < ft_strlen(s1))
			res[i] = s1[i];
		while (++i2 < ft_strlen(s2))
			res[i + i2] = s2[i2];
		res[i + i2] = '\0';
	}
	return (res);
}

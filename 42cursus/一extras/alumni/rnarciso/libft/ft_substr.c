/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:09 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/22 19:35:59 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	size_t			i_2;
	size_t			i_3;
	unsigned char	*res;

	i = ft_strlen(s);
	if (start > i || start < 0)
		len = 0;
	if (len > i - start)
		len = i - start;
	res = (unsigned char *)malloc(len + 1);
	if (!s || !res)
		return (NULL);
	i_2 = 0;
	i_3 = 0;
	while (s[i_2])
	{
		if (i_2 >= start && i_3 < len)
			res[i_3++] = s[i_2];
		i_2++;
	}
	res[i_3] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afgoncal <massenaafonso1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:40:59 by afgoncal          #+#    #+#             */
/*   Updated: 2022/11/10 13:33:14 by afgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;
	unsigned int	slen;

	slen = (unsigned int)ft_strlen(s);
	if (start >= slen)
		str = malloc(1);
	else if (len >= (size_t)slen)
		str = (char *)malloc(sizeof(char) * slen - start + 1);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	if (start < slen)
	{
		while (len > 0 && s[start] && start < slen)
		{
			str[i++] = s[start++];
			len--;
		}
	}
	str[i] = '\0';
	return (str);
}

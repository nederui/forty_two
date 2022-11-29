/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:55:01 by amak              #+#    #+#             */
/*   Updated: 2022/11/20 00:21:01 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	pos;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(&s[start]))
		len = ft_strlen(&s[start]);
	temp = (char *)malloc((sizeof(char) * len) + 1);
	pos = 0;
	if (temp == NULL)
		return (NULL);
	while (pos < len)
	{
		temp[pos] = s[start + pos];
		pos++;
	}
	temp[pos] = '\0';
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:58:23 by amak              #+#    #+#             */
/*   Updated: 2022/11/20 02:55:59 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	length;
	int		pos;

	if (s == NULL || f == NULL )
		return (NULL);
	length = ft_strlen((char *)s);
	result = (char *)ft_calloc(length + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		result[pos] = f(pos, s[pos]);
		pos++;
	}
	return (result);
}

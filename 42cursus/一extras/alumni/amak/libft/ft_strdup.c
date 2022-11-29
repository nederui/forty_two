/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:34:06 by amak              #+#    #+#             */
/*   Updated: 2022/11/08 05:42:37 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		lenth;
	int		pos;
	char	*pnt;

	lenth = ft_strlen((char *)s);
	pnt = (char *)malloc(lenth + 1);
	if (pnt == NULL)
		return (NULL);
	pos = 0;
	while (s[pos] != '\0')
	{
		pnt[pos] = s[pos];
		pos++;
	}
	pnt[pos] = '\0';
	return (pnt);
}

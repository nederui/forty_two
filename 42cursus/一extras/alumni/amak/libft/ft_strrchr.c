/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:42:57 by amak              #+#    #+#             */
/*   Updated: 2022/11/20 00:02:33 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	pos = ft_strlen((char *)s);
	while (pos >= 0)
	{
		if (s[pos] == (unsigned char)c)
			return (&((char *)s)[pos]);
		pos--;
	}
	return (0);
}

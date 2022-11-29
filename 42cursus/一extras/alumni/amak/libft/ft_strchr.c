/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:42:57 by amak              #+#    #+#             */
/*   Updated: 2022/11/20 00:01:08 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		pos;
	char	*str;

	pos = 0;
	str = (char *)s;
	while (str[pos])
	{
		if (str[pos] == (unsigned char)c)
			return (&str[pos]);
		pos++;
	}
	if (str[pos] == (char)c)
		return (&str[pos]);
	return (NULL);
}

//	The strchr() and strrchr() functions return a pointer to the matched
//  character or NULL  if  the character is not found.  The terminating null
//  byte is considered part of the string, so that if c is specified as '\0', 
//	these functions return a pointer to the terminator.

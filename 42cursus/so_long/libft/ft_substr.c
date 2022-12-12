/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:21:59 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:38:32 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t buffer)
{
	char	*substr;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (buffer > s_len - start)
		buffer = s_len - start;
	substr = (char *) malloc(buffer + 1);
	if (substr)
	{
		ft_memmove(substr, s + start, buffer);
		substr[buffer] = '\0';
	}
	return (substr);
}

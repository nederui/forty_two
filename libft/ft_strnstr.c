/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:19:39 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/30 14:19:50 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i_needle;

	i = 0;
	i_needle = 0;
	if (!needle)
		return((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i] == needle[i_needle] && i < len)
		{
			i_needle++;
			i++;
		}
		if (!needle[i_needle])
			return((char *)haystack+i-i_needle);
		else
		{
			i = i - i_needle;
			i_needle = 0;
			i++;
		}
	}
	return (0);
}

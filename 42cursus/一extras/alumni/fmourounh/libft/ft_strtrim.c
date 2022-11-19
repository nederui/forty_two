/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:58:08 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:17 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimstart(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (*s1)
	{
		j = 0;
		while (set[j] && *s1 != set[j])
			j++;
		if (!set[j])
			return (i);
		s1++;
		i++;
	}
	return (-1);
}

static int	ft_trimend(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = (int)ft_strlen(s1);
	while (i-- > 0)
	{
		j = 0;
		while (set[j] && s1[i] != set[j])
			j++;
		if (!set[j])
			return (i);
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	int		start;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	if (!*s1)
		return ("");
	start = ft_trimstart(s1, set);
	if (start < 0)
		return ("");
	len = ft_trimend(&s1[start], set) + 1;
	if (len < 0)
		return (NULL);
	trim = ft_calloc(len + 1, sizeof(char));
	if (!trim)
		return (NULL);
	i = 0;
	while (i < len)
		trim[i++] = s1[start++];
	return (trim);
}

/*
	find start of string, assign to start
	count total bytes from s1[start] to nullbyte
		then count bytes until *s1 does not match set
		and assign to len
	and then calloc(len + 1) into trim
	and copy bytes from s1[start] to s1[start + len]
*/

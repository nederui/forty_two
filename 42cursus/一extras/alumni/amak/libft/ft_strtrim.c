/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:31:40 by amak              #+#    #+#             */
/*   Updated: 2022/11/20 02:46:05 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	begin_pos(char const *s1, char const *set)
{
	int		pos_s1;
	int		pos_set;

	pos_s1 = 0;
	pos_set = 0;
	while (set[pos_set] && s1[pos_s1] != '\0')
	{
		if (s1[pos_s1] == set[pos_set])
		{	
			pos_s1++;
			pos_set = 0;
		}	
		else
			pos_set++;
	}
	return (pos_s1);
}

static	int	end_pos(char const *s1, char const *set)
{
	int		pos_s1;
	int		pos_set;

	pos_s1 = (int)ft_strlen((char *)s1) - 1;
	pos_set = 0;
	while (set[pos_set] && pos_s1 >= 0)
	{
		if (s1[pos_s1] == set[pos_set])
		{	
			pos_s1--;
			pos_set = 0;
		}	
		else
			pos_set++;
	}
	return (pos_s1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		initial;
	int		final;
	int		pos;

	initial = begin_pos(s1, set);
	final = end_pos(s1, set);
	if (initial > final)
		return (ft_strdup(""));
	pos = 0;
	result = (char *)malloc(final - initial + 2);
	if (result == NULL)
		return (NULL);
	while (initial <= final)
	{
		result[pos] = s1[initial];
		pos++;
		initial++;
	}
	result[pos] = '\0';
	return (result);
}

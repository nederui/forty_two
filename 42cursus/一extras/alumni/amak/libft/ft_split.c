/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:08:49 by amak              #+#    #+#             */
/*   Updated: 2022/11/14 18:47:21 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nr_words(char const *s, char c)
{
	int		result;
	int		pos;
	int		state;

	result = 0;
	pos = 0;
	state = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			state = 0;
		else
		{
			if (state == 0)
			{
				result++;
				state = 1;
			}	
		}
		pos++;
	}
	return (result);
}

static	int	first_word_length(const char *s, char c)
{
	int		pos;

	pos = 0;
	while (s[pos] != c && s[pos] != '\0')
		pos++;
	return (pos);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		pos;
	int		pos_res;
	int		word_size;

	pos = 0;
	pos_res = 0;
	result = (char **)ft_calloc(nr_words(s, c) + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (s[pos])
	{
		if (s[pos] == c)
			pos++;
		else
		{
			word_size = first_word_length(&s[pos], c);
			result[pos_res] = (char *)ft_calloc(word_size + 1, sizeof(char));
			ft_strlcpy(result[pos_res], &s[pos], word_size + 1);
			pos_res++;
			pos = pos + word_size;
		}
	}
	return (result);
}

// state: 0 = spacer | 1 = word
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joacaeta <joacaeta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:40:22 by joacaeta          #+#    #+#             */
/*   Updated: 2022/10/09 17:40:22 by joacaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strleng(char const *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r;
	int		i;
	int		j;

	i = 0;
	j = 0;
	r = malloc(strleng(s1) + strleng(s2) + 1);
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		r[i++] = s2[j++];
	}
	r[i] = '\0';
	return (r);
}

// int main (void)
// {
//     printf("%s", ft_strjoin("", ""));
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:15:38 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:17 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	dup = malloc((sizeof(char) * i) + 1);
	if (!dup)
		return (NULL);
	ft_bzero(dup, i + 1);
	while (i > 0)
	{
		i--;
		dup[i] = s[i];
	}
	return (dup);
}

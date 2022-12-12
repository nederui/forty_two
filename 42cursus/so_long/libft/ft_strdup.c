/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:16:29 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/12/09 18:38:15 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*string;
	size_t	len_s1;

	len_s1 = ft_strlen((char *)s1);
	string = (char *) malloc(len_s1 + 1);
	if (string)
	{
		ft_memcpy(string, s1, len_s1);
		string[len_s1] = '\0';
	}
	return (string);
}

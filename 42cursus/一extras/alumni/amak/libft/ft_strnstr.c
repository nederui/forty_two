/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:59:01 by amak              #+#    #+#             */
/*   Updated: 2022/11/10 01:17:23 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	p_b;
	size_t	p_cmp;

	p_b = 0;
	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	if (ft_strlen((char *)big) < ft_strlen((char *)little))
		return (0);
	while (big[p_b] != '\0' && (p_b < len))
	{
		p_cmp = 0;
		if (big[p_b + p_cmp] == little[p_cmp])
		{
			while ((big[p_b + p_cmp] == little[p_cmp]) && ((p_b + p_cmp) < len))
			{
				p_cmp++;
				if (little[p_cmp] == '\0')
					return ((char *)big + p_b);
			}
		}
		p_b++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmouronh <fmouronh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 23:58:08 by fmouronh          #+#    #+#             */
/*   Updated: 2022/11/07 04:39:04 by fmouronh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	find_nbr(const char *nptr)
{
	size_t	i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (ft_isdigit(nptr[i]))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		num;
	int		pow;
	size_t	i;

	while (*nptr && (*nptr == ' ' || ('\a' <= *nptr && *nptr <= '\r')))
		nptr++;
	num = 0;
	i = find_nbr(nptr);
	if (!i)
		return (0);
	pow = 1;
	while (i-- > 1)
	{
		num += (nptr[i] - '0') * pow;
		pow *= 10;
	}
	if (ft_isdigit(nptr[i]))
		num += (nptr[i] - '0') * pow;
	else if (nptr[i] == '-')
		return (-num);
	return (num);
}

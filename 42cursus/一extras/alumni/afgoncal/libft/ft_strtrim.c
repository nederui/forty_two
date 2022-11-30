/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afgoncal <massenaafonso1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:44:08 by afgoncal          #+#    #+#             */
/*   Updated: 2022/11/10 15:49:04 by afgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static int	check_trim(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static void	put_in_arr(char *arr, const char *src, int start, int end)
{
	int	i;

	i = 0;
	while (start <= end)
		arr[i++] = src[start++];
	arr[i] = '\0';
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;

	start = 0;
	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	return (ft_substr(s1, start, len));
}

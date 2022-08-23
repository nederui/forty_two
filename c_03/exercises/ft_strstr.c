/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:48:23 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/18 23:48:25 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i_needle;
	int	i_haystack;

	i_needle = 0;
	i_haystack = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i_haystack] != '\0')
	{
		if (str[i_haystack] == to_find[i_needle])
		{
			while (to_find[i_needle] != '\0'
				& str[i_haystack] == to_find[i_needle])
			{
				i_haystack++;
				i_needle++;
			}
		}
		if (to_find[i_needle] == '\0')
			return (&str[i_haystack - i_needle]);
		i_haystack++;
		i_needle = 0;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:26 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/16 21:43:29 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
				return (0);
			i++;
		}
		return (1);
	}
	return (1);
}

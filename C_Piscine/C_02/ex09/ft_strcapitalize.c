/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 05:36:16 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/17 05:36:17 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_make_it_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 64 && str[i] < 91)
			str[i] += 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	ft_make_it_lowercase (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] > 96 && str[i] < 123)
		{
			if (!(str[i - 1] > 47 && str[i - 1] < 58))
			{
				str[i] -= 32;
				i++;
			}
			while (str[i] > 96 && str[i] < 123)
				i++;
		}
		i++;
	}
	return (str);
}

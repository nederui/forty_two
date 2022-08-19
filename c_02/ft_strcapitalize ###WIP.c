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

// char	*ft_strcapitalize(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\0')
// 	{
// 		if ((str[i] > 47 && str[i] < 58) || (str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123))
// 		{
// 			if ( !(str[i - 1] < 48 && str[i] > 57)
// 			{
// 				str[i] = str[i] - 32;
				
// 			}
// 		}
// 		i++;
// 	}
// 	return (str);
// }

// The first condition looks for lowercased-first letters of a word and
// "uppercases" them (str[i] - 32);
// - by checking if the char before it is a space [ascii decimal set: 32]

// The second condition looks for any uppercased letters which are not 
// the first letter of a word and "lowercases" them (str[i] + 32);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 96 && str[i] < 123)
			&& (str[i - 1] < 48 || str[i - 1] > 122))
				str[i] = str[i] - 32;
		else
			if ((str[i] > 64 && str[i] < 91)
				&& (str[i - 1] > 47 && str[i - 1] < 123))
					str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
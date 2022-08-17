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

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] > 47 && str[i] < 91) || str{i} > 96 && str[i] < 123)
		{
			
		}
		i++;
	}
	return (str);
}

Create a function that capitalizes the first letter of each word 
and transforms all other letters to lowercase.

•A word is a string of alphanumeric characters.


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 00:56:18 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/14 00:56:19 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	ft_strlen(char *str)
// {
// 	int	lenght;

// 	lenght = 0;
// 	while (*str != '\0')
// 	{
// 		str++;
// 		lenght++;
// 	}
// 	return (lenght);
// }
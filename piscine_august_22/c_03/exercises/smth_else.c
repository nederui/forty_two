/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 23:28:45 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/17 23:28:46 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i_s1;
	unsigned int	i_s2;
	unsigned int	n;

	i_s1 = 0;
	i_s2 = 0;
	n = 0;

	while (s1[i_s1] != '\0')
		i_s1++;

	while (s2[i_s2] != '\0')
		i_s2++;

	n = (i_s2 - i_s1);

	return (n);
}

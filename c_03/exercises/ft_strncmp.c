/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 18:53:38 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/18 18:53:40 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 0)
	{
		while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
			i++;
		return ((unsigned)s1[i] - (unsigned)s2[i]);
	}
	return (0);
}

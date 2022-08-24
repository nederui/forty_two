/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:28:06 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/18 21:28:07 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i_src;
	unsigned int	i_dest;

	i_src = 0;
	i_dest = 0;
	if (nb > 0)
	{
		while (dest[i_dest] != '\0')
			i_dest++;
		while (src[i_src] != '\0' && i_src < nb)
		{
			dest[i_dest + i_src] = src[i_src];
			i_src++;
		}
		dest[i_dest + i_src] = '\0';
		return (dest);
	}
	return (dest);
}

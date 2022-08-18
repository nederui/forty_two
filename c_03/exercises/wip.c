/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:15:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/17 08:15:44 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_i;

	i = 0;
	dest_i = 0;
	while (dest[dest_i] != '\0')
	{
		dest_i++;
	}
	if (size == 0 || dest_i > size)
		return (size);
	while (src[i] != '\0' && i < size - dest_i - 1)
	{
		dest[dest_i + i] = src[i];
		i++;
	}	
	dest[dest_i + i] = '\0';
	return (dest_i + i);
}







// DESCRIPTION
//      The strlcpy() and strlcat() functions copy and concatenate strings with the same input parameters and output result as snprintf(3).  They a
// re
//      designed to be safer, more consistent, and less error prone replacements for the easily misused functions strncpy(3) and strncat(3).

//      strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-termination if there is room.  Note that room for th
// e NUL
//      should be included in dstsize.

//      strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating the result if dstsize is not 0.

//      strlcat() appends string src to the end of dst.  It will append at most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
//      unless dstsize is 0 or the original dst string was longer than dstsize (in practice this should not happen as it means that either dstsize is
//      incorrect or that dst is not a proper string).

//      If the src and dst strings overlap, the behavior is undefined.
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 18:22:57 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/14 18:22:58 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*lenght;

	lenght = 0;
	while (*lenght != '\0')
	{
		dest = src;
		lenght++;
		return (dest);
	}
	return (src);
}

/*
man strcpy

char chararray[6];

	     (void)strncpy(chararray, "abc", sizeof(chararray));

     The following sets chararray to ``abcdef'':

	     char chararray[6];

	     (void)strncpy(chararray, "abcdefgh", sizeof(chararray));

     Note that it does not NUL terminate chararray because the length of the source
     string is greater than or equal to the length argument.

     The following copies as many characters from input to buf as will fit and NUL termi-
     nates the result.  Because strncpy() does not guarantee to NUL terminate the string
     itself, this must be done explicitly.

	     char buf[1024];

	     (void)strncpy(buf, input, sizeof(buf) - 1);
	     buf[sizeof(buf) - 1] = '\0';

     This could be better achieved using strlcpy(3), as shown in the following example:

	     (void)strlcpy(buf, input, sizeof(buf));

	     
*/
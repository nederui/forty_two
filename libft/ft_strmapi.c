/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:18:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/10/31 01:56:33 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*string;

	i = 0;
	string = (char *) malloc(ft_strlen(s) + 1);
	if (string)
	{
		if (s && f)
		{	
			while (s[i])
			{
				string[i] = f(i, &s[i]);
				i++;
			}
			string[i] = '\0';
		}
	}
	return (string);
}

// Parameters  s: The string on which to iterate.
// 			f: The function to apply to each character.

// Return      The string created from the successive applications of ’f’.
// 			NULL if the allocation fails.

// External functs. malloc

// Description Applies the function ’f’ to each character of the
// 			string ’s’, and passing its index as first argument
// 			to create a new string (with malloc(3)) resulting
// 			from successive applications of ’f’.
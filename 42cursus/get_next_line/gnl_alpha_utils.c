/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_alpha_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 03:33:49 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/28 04:37:37 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// looks for '\n' in the given string
int	ft_newline_finder(char *pouch)
{
	int	i;

	if (pouch == NULL)
		return (0);
	i = 0;
	if (ft_strchr(pouch, '\n') != 0)
		return (1);
	else
		return (0);
}

// calculates the number of characters in the current line (including '\n', 
// if there is one) and allocates memory accordingly
// void	ft_line_generator(char *line, char *pouch)
// {
// 	int	i;
// 	int	len;

// 	len = 0;
// 	while (pouch)
// 	{
		
// 	}
	
// }

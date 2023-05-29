/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freewillie.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:59:15 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/05/29 21:14:11 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// frees the data previously allocated in a char matrix
void	freewillie(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		++i;
	}
	free(array);
	array = NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:57:00 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/22 17:40:38 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_printf/ft_printf.h"

int	main(void)
{
	FILE	*fh;
	char	c;

	fh = fopen("file.txt", "r");
	if (fh)
	{
		while ((c = fgetc(fh)) != EOF)
			ft_putchar_int(c);
		fclose(fh);
	}
	else
		ft_printf("Error opening file.\n");
	return (0);
}
read(1, *buffer, 5);
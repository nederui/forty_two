/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 23:13:55 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/16 01:32:36 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	max(int num_args, ...)
{
	va_list	args;

	va_start(args, num_args);

	int	max = 0;
	for (int i = 0; i < num_args; i++)
	{
		int	x = va_arg(args, int);
		if (i == 0)
			max = x;
		else if (x > max)
			max = x;
	}
	va_end(args);
	return (max);
}

int	main(void)
{
	int	max_num = max(4, 12424240, 12, 14, 164545);
	printf("max_num: %d\n", max_num);
	
	return (0);
}

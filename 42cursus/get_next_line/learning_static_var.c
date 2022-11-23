/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learning_static_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:47:04 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/22 22:47:05 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	function()
{
	char	var = 'A';

	printf("var:%c\n", var);
	var = 'B';
}

int	main(void)
{
	function();
	function();
	function();
	return (0);
}

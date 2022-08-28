/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trying_out_C.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:51:11 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/05 15:38:59 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int factorial(int number)
{
	int factorial = 1;
	
	for (int i = number; i > 1; i--)
	{
		factorial = factorial * i;
	}

	return factorial;
}

void outputFactorial(int input)
{
	printf("The factorial of %d is %d.\n", input, factorial(input));
}

int main()
{
	for(int i= 0; i < 10; i++)
	{
		outputFactorial(i);
	}
	return 0;
}

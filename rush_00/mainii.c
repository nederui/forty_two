/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainii.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:28:21 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 16:08:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	// calling out "rush.c" program
#include <unistd.h>		// tell the computer to use unistd.h library

void rush04ii(char x, char y);
void ft_putcahrii();

int main()				// defining the main, which runs rush()
{						// written in "rush04.c"
	rush04ii(3, 3);
						// the values 'x' and 'y' define the
}						// the height & width of our rectangle
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:28:21 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 13:31:15 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

						// calling out "rush.c" program
#include <unistd.h>		// tell the computer to use unistd.h library

void rush_test(char width, char length);
// void putchar_test(char width, char lenght);

int main()				// defining the main, which runs rush()
{						// written in "rush04.c"
	rush_test(4, 4);
						// the values 'x' and 'y' define the
}						// the height & width of our rectangle
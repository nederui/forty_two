/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:28:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 00:17:31 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>                     // tell the computer to use unistd.h library

void rush(char width, char height)      // defining rush() & 2 vars (x, y)
{
    char x = width;                     // setting vars 'x' & 'y' with
    char y = height;                    // the user-inputed values of width & height

// display the top-left vertice:
    
    write(1, "A", 1);
    x--;
    
// display the top edge:
    
    while(x > 1)
    {
        write(1, "B", 1);
        x--;
    }

// display the top-right vertice:

    write(1, "C\n", 2);

// reasign the value of 'width' to 'x':

    x = width;

// display the left & right edges:
    
    while(y > 1)
    {
        if(y == height)
        {
            write(1, "B", 1);
            x--;
        } else
        {
            write(1, " ", 1);
            x--;
        }
        y--;
    }
    
    write(1, "B\n", 2);
    
    x = width;
    
    write(1, "C", 1);
    x--;
    
    while(x > 1)
    {
        write(1, "B", 1);
        x--;
    }   
    write(1, "A\n", 2);
}
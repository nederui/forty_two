/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:28:28 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 13:42:48 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void putchar_test(void);
void rush_test(char width, char length)
{
    if(width == 0 || length == 0)       //
        {                               // zero-proofing rush_test()
            write(1, "\n", 1);          //
        } else    
    {    
    char x = width;
    char y = length;
    
    while(y > 0)
    {
        putchar_test();
        y--;
        write(1, "\n", 2);
    }
    }

}
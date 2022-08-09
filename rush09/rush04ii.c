/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04ii.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:48:21 by carloda-          #+#    #+#             */
/*   Updated: 2022/08/07 17:26:53 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
void ft_putcharii(char c)
        {
            write(1, &c, 1)
        }

void rush04ii(char width, char lenght)
{
    char x = width;
    char y = lenght;
    
    if(x == 0 || y == 0)                //
        {                               // zero-proofing rush_test()
            write(1, 0, 1);             //
        } else{
            while(x > 0)
        {
            void ft_putcharii();
            if(x == width)
    {
        write(1, "A", 1);
        }
    if(x == 1)
        {
            write(1, "C\n", 2);
            }
    
    else{
        if(y == lenght)
        {
            write(1, "B", 1);
            } else
            {
                write(1, " ", 1);
                }
                 }
                 x--;
        }

        while(y > 0)
        {
            if(y == 1){
                write(1, 0, 1);
            }
        
            ft_putcharii('A');
            y--;
            }  
        }
}


//// if x or y = 0: null


// else:
// while x>0: 
// write:
// A if x == width
// if x = 1: write C
// else: write " "

//x--

// while y>0: <after fn(x)> \n
// y--
// if y = 1: null
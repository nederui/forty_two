/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:48:21 by carloda-          #+#    #+#             */
/*   Updated: 2022/08/07 23:41:32 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void rush04(char width, char lenght)
{
    char x = width;
    char y = lenght;
    
    if(x == 0 || y == 0)                
        {                               
            write(1, 0, 1);             
        } else
        {
            write(1, "A", 1);
        
        while (x > 2)
        {
            write(1, "B", 1);
            x--;
            }
        
        if (x >= 2)
        {
            write(1, "C", 1);
            }
        
        write(1, "\n", 1);
 
        while (y > 2)
        {
            write(1, "B", 1);
            x = width;
            
            while (x > 2){
            
            write(1, " ", 1);
            x--;
            }
            
            if(x >=2)
            {
                write(1, "B", 1);
                }
                y--;
                
                write(1, "\n", 1);
                }
                
                if (y >= 2)
                {
                    x = width;
                    write(1, "C", 1);
                    while (x > 2)
                    {
                        write(1, "B", 1);
                        x--;
                    }
                    
                    if (x > 1)
                    {
                        write(1, "A\n", 2);
                    } else
                    {write(1, "\n", 2);}
            }
        }
}
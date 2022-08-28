/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:28:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 22:32:21 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void ft_putchar(char width, char lenght)
{
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
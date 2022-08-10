/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:15:19 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/10 16:52:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putcharing();

void    writeFirstLine(int i)
{
    if (x >= 1)
    {
        ft_putcharing('A');
    }
    
    while (x > 2)
    {
        ft_putcharing('B');
            x--;
    }

    if(x == 2 && x > 1)
    {
        ft_putcharing('C');
    }
}

void    writeMiddleLine()
{ 
    if (x >= 1)
    {
        ft_putcharing('B');
    }
    
    while (x > 2)
    {
        ft_putcharing(' ');
            x--;
    }

    if(x == 2 && x > 1)
    {
        ft_putcharing('B');
    }  
}

void    writeLastLine()
{
    if (x >= 1)
    {
        ft_putcharing('C');
    }
    
    while (x > 2)
    {
        ft_putcharing('B');
            x--;
    }

    if(x == 2 && x > 1)
    {
        ft_putcharing('A');
    }
}

void current_position(posX, posY)
{
    int x = posX;
    int y = posY;
    
    if (y == posY)
    {
        write_first_line(x, y);
        ft_putcharing('\n');
        y--;
        x = posX;
    }
    while (y < posY && y > 2)
    {
        write_middle_line(x, y);
        ft_putcharing('\n');
        y--;
        x = posX;
    }   
    if (y == 2)
    {
        write_last_line(x, y);
        ft_putcharing('\n');
        y--;
        x = posX;
    }
}

void    rushing(posX, posY)
{   
    while (y > 0)
    {
        current_position(x, y);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 18:15:19 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 21:17:22 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putcharing();

/*
void    writeFirstLine();

void    writeMiddleLine();

void    writeLastLine();
*/

void    rushing(int posX, int posY)
{
    int x = posX;
    int y = posY;
    
   // currentPosition();
    
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
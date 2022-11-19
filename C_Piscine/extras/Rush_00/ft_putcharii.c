/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:28:25 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/07 16:06:36 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putcharii(char width, char lenght)
{
    char x = width;
    char y = lenght;
    
    if(x == width)
    {
        write(1, "A", 1);
        }
    if(x == 1)
        {
            write(1, "C", 1);
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
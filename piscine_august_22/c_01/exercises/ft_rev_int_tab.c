/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 17:39:08 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/08/14 17:39:11 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	pouch;

	i = 0;
	while (i < size)
	{
		pouch = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = pouch;
		size--;
		i++;
	}
}

// The inputed parameters are an array & its size (= nr of elements).
//
// As I don't know what size it will be, I'll use it's variable (=size) as a
// referece to go through its lenght.
// 
// I declared i to be a reference to *tab's current element, starting with 0)
//
// Afterwards I started a while loop with a stright swap between:
// - tab's first element (tab[i], where i = o)
// - my swapper var (pouch)
// - tab's last element (tab[size - 1])
//
// last element = tab[size -1] <-- because, while its lenght ranges from
// 1 to its lenght's value, an array's elements start in position 0 (size -1)
//
// In the end of each loop iteration, I increase i (element's position)
// and I decrease size (= reference to the array's actual lenght), so that
// the values of i and size meet in the middle position of the array's lenght.
// 
// every array's position with its counter-part.
// This while loop will happen until i = size, when we'll have swapped
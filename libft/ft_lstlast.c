/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:23 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 01:55:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int		nodes;
	t_list	*ptr;

	nodes = 0;
	ptr = lst;
	while (ptr)
	{
		ptr = ptr->next;
		nodes++;
	}
	ptr = lst;
	while (nodes > 1)
	{
		ptr = ptr->next;
		nodes--;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:35:11 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 01:53:20 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		nodes;
	t_list	*ptr;

	ptr = lst;
	nodes = 0;
	while (ptr)
	{
		ptr = ptr->next;
		nodes++;
	}
	return (nodes);
}


// int	ft_lstsize(t_list *lst)
// {
// 	int		nodes;

// 	nodes = 0;
// 	while (lst)
// 	{
// 		lst = lst->next;
// 		nodes++;
// 	}
// 	return (nodes);
// }

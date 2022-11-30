/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afgoncal <massenaafonso1@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:43:01 by afgoncal          #+#    #+#             */
/*   Updated: 2022/11/23 15:05:21 by afgoncal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*nnode;

	if (!lst)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		nnode = ft_lstnew(f(lst -> content));
		if (!nnode)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, nnode);
		lst = lst -> next;
	}
	return (new_lst);
}

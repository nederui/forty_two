/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:01:09 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/28 17:10:31 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (newlist)
	{
		node = newlist;
		lst = lst->next;
		while (lst != 0)
		{
			node->next = ft_lstnew(f(lst->content));
			if (!node->next)
			{
				ft_lstclear(&newlist, del);
				return (NULL);
			}
			lst = lst->next;
			node = node->next;
		}
		node->next = NULL;
	}
	return (newlist);
}

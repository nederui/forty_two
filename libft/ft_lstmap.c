/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:12:34 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/14 19:13:43 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;
	
	if (!lst || !f)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (new_list)
	{
		node = new_list;
		lst = lst->next;
		while (lst != NULL)
		{
			node->next = ft_lstnew(f(lst->content));
			if (!node->next)
			{
				ft_lstclear(&new_list, del);
				return (NULL);
			}
			lst = lst->next;
			node = node->next;
		}
		node->next = NULL;
	}
	return (new_list);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:49:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/09 05:53:10 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pouch;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		pouch = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pouch;
	}
	lst = NULL;
}

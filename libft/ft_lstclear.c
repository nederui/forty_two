/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:49:42 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/08 19:57:43 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst && del)
	{
		ptr = *lst;
		while (ptr != NULL)
		{
			(*del)(ptr->content);
			free(ptr);
			ptr = ptr->next;
		}
		free(*lst);
		lst = NULL;
	}
}

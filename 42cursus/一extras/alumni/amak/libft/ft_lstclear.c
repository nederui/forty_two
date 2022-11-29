/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:05:44 by amak              #+#    #+#             */
/*   Updated: 2022/11/19 23:56:54 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux_pos;
	t_list	*aux_before;

	if (*lst != NULL)
	{
		aux_pos = *lst;
		while (aux_pos->next != NULL)
		{
			aux_before = aux_pos;
			aux_pos = aux_pos->next;
			ft_lstdelone(aux_before, del);
		}
		ft_lstdelone(aux_pos, del);
	}
	*lst = NULL;
}

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL
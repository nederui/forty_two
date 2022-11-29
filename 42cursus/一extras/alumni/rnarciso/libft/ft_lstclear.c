/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:43:46 by rnarciso          #+#    #+#             */
/*   Updated: 2022/11/28 16:56:29 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*toot;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		toot = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = toot;
	}
	lst = NULL;
}

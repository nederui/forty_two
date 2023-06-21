/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_secondtolast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:47:01 by nfilipe-          #+#    #+#             */
/*   Updated: 2023/06/21 19:01:11 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*lst_secondtolast(t_list *lst)
{
	t_list	*secondtolast;

	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		secondtolast = lst;
		lst = lst->next;
	}
	return (secondtolast);
}

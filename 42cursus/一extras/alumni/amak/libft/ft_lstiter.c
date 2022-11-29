/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amak <amak@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:45:47 by amak              #+#    #+#             */
/*   Updated: 2022/11/19 23:55:51 by amak             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	if (lst == NULL || f == NULL)
		return ;
	else
	{
		aux = lst;
		while (aux->next != NULL)
		{
			f(aux->content);
			aux = aux->next;
		}
		f(aux->content);
	}
}

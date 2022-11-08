/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:52:23 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/07 23:36:55 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct t_list
{
	void			*content;
	struct t_list	*next;
}					t_list;

t_list	*ft_lstlast(t_list *lst)
{
	void	*ptr;

	while (ptr)
		ptr = lst->next;
	return (ptr);
}

// t_list	*ft_lstlast(t_list *lst)
// {
// 	while (lst)
// 		lst = lst->next;
// 	return (lst);
// }

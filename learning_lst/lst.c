/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:06:51 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/07 20:41:32 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct t_Node {
	int				x;
	struct t_Node	*next;
}	t_Node;

int	main(void)
{
	t_Node	root;

	root.x = 15;
	root.next = malloc(sizeof(t_Node));
	root.next->x = -2;
	root.next->next = NULL;

	printf("First:%d\n", root.x);
	printf("Second:%d\n", root.next->x);
	free(root.next);
	return (0);
}

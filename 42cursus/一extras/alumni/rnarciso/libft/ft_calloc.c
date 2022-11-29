/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnarciso <rnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:49:09 by merlin            #+#    #+#             */
/*   Updated: 2022/11/28 18:52:38 by rnarciso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t n)
{
	size_t	i;
	void	*str;

	if (nitems == 0 || n == 0)
	{
		str = malloc(NULL);
		return (str);
	}
	i = nitems * n;
	str = malloc(i);
	if (str == NULL)
		return (NULL);
	else
		ft_bzero(str, i);
	return (str);
}

/*
#include <stdio.h>

int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d\n",a[i]);
   }
   free( a );
   
   return(0);
}
*/
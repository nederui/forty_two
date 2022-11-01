/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfilipe- <nfilipe-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:40:51 by nfilipe-          #+#    #+#             */
/*   Updated: 2022/11/01 03:51:14 by nfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **split(char *string, char *separators, int *count)
{
	int	i;
	int	j;
	int	len;
	int	old_i;
	char	buffer[16384];
	int	string_index;

	len = strlen(string);
	i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (strchr(separators, string[i]) == NULL)
				break;
			i++;
		}
		old_i = i;
		while (i < len)
		{
			if (strchr(separators, string[i]) != NULL)
				break;
			i++;
		}
		if (i > old_i)
			*count = *count + 1;
	}
	char **strings = malloc(sizeof(char *) * *count);
	i = 0;
	while (i < len)
	{
		while (i < len)
		{
			if (strchr(separators, string[i]) == NULL)
				break;
			i++;
		}
		j = 0;
		while (i < len)
		{
			if (strchr(separators, string[i]) != NULL)
				break;
			buffer[j] = string[i];
			i++;
			j++;
		}
		if (j > 0)
		{	
			buffer[j] = '\0';
			
			int	to_allocate = sizeof(char) * (strlen(buffer) + 1);

			strings[string_index] = malloc(to_allocate);

			strcpy(strings[string_index], buffer);

			string_index++;
		}
	}
	if (strings)
		return (strings);
	else
		return(0);
}

int main(void)
{
	char s[] = "To be, or not to be, that is the question.";

	int	count_strings = 0;

	char **split_strings = split(s, " ,.", &count_strings);

	for (int i = 0; i < count_strings; i++)
		printf("%s\n", split_strings[i]);
	for (int i = 0; i < count_strings; i++)
		free(split_strings[i]);
	
	free(split_strings);
	
	return (0);
}

#include <stdlib.h>

void	*ft_print_memory(void *addr, unsigned int size);

// returns 0 if there is no sequential charset in str
int	parse_str(int *index, char *str, char *charset)
{
	int	len;
	int	done;
	int	i;

	len = 0;
	done = 0;
	while (!done && *str)
	{
		i = 0;
		while (*(str + i) == charset[i])
			i++;
		if (charset[i] == '\0')
		{
			*index += len + i;
			done = 1;
		}
		else
		{
			len++;
			str++;
		}
	}
	if (len == 0)
		return (1);
	if (*str == '\0')
	{
		*index += len;
		return (0);
	}
	return (0);
}

int	count_substr(char *str, char *charset)
{
	int	is_empty;
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		is_empty = parse_str(&i, &str[i], charset);
		if (!is_empty)
			count++;
	}
	return (count);
}

void	assign_str(char *str, char *charset, char ***split)
{
	int	is_empty;
	int	len;
	int	s;
	int	i;
	int	j;
	int	l;

	len = 0;
	while (charset[++len]);

	s = 0;
	i = 0;
	while (str[i] != '\0')
	{
		j = i;
		is_empty = parse_str(&i, &str[i], charset);
		if (!is_empty)
		{
			(*split)[s] = (char *)malloc(i - j);
			l = 0;
			while (j < i - len)
			{
				(*split)[s][l] = str[j];
				l++;
				j++;
			}
			if (str[i] == '\0')
				(*split)[s][l++] = str[j];

			(*split)[s][l] = '\0';
			s++;
		}
	}
	(*split)[s] = (char *)malloc(1);
	(*split)[s][0] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int	buf;

	buf = count_substr(str, charset);
	split = (char **)malloc((buf * 8) + 8);
	assign_str(str, charset, &split);
	return (split);
}

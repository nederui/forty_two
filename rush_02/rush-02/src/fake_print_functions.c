#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "rush02.h"
#include <stdio.h>

#define LINE_MAX_LENGTH 100

// void print_nb(char a, char b)
// {
// 	char	*to_print;
// 	char	*str;

// 	if (a == '0')
// 	{
// 		str =  malloc(2*sizeof(char));
// 		str[0] = b;
// 		str[1] = '\0';
// 	}
// 	else
// 	{
// 		str =  malloc(3*sizeof(char));
// 		str[0] = a;
// 		str[1] = b;
// 		str[2] = '\0';				
// 	}
// 	to_print = find_key("numbers_specific.dict", str);
// 	free(str);
// 	ft_putstr(to_print);
// 	free(to_print);
// }

// DONE

// void	read_line(char *buf, int file_descriptor, int *done)
// {
// 	read(file_descriptor, buf, 1);
// 	while (*buf != '\n' && *buf != 0)
// 	{
// 		buf++;
// 		read(file_descriptor, buf, 1);
// 	}
// 	if (*buf == 0)
// 		*done = 1;
// 	*buf = 0;
// }

// int	ft_strlen(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void	ft_putstr(char *str)
// {	
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// }

// int	match_nbr(char *str, char *to_find)
// {
// 	if (!*to_find && (*str < '0' || *str > '9' ))
// 		return (1);
// 	else if (!*str)
// 		return (0);
// 	if (*str == *to_find)
// 		return (match_nbr(str + 1, to_find + 1));
// 	return (0);
// }

// done
// char	*ft_strdup_printable(char *src)
// {
// 	char	*dest;
// 	char	*orig_dest;

// 	orig_dest = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
// 	dest = orig_dest;
// 	if (dest)
// 	{
// 		while (*src >= 32 && *src < 127)
// 		{
// 			*dest++ = *src++;
// 		}
// 		*dest = 0;
// 	}
// 	return (orig_dest);
// }

// "done", has more than 25 lines
// char	*find_key(char *file, char *key)
// {
// 	int		done;
// 	int		file_descriptor;
// 	char	*line;
// 	char	*value;

// 	value = (char *) 0;
// 	file_descriptor = open(file, O_RDONLY);
// 	if (file_descriptor > 0)
// 	{
// 		done = 0;
// 		line = (char *) malloc(LINE_MAX_LENGTH);
// 		while (!done)
// 		{
// 			read_line(line, file_descriptor, &done);
// 			if (match_nbr(line, key))
// 			{
// 				while (*line == ' ' || (*line >= '0' && *line <= '9'))
// 					line++;
// 				if (*line++ != ':')
// 					continue ;
// 				while (*line == ' ')
// 					line++;
// 				value = ft_strdup_printable(line);
// 				break ;
// 			}
// 		}
// 		close(file_descriptor);
// 		return (value);
// 	}
// 	return ((char *) 0);
// }

// DONE
// char	*correctlength(char *str)
// {
// 	int		length;
// 	int		bonuszero;
// 	char	*new_string;
// 	int		i;

// 	length = ft_strlen(str);
// 	bonuszero = 0;
// 	if (length % 3 != 0)
// 	{
// 		bonuszero = 3 - (length % 3);
// 	}
// 	length = length + bonuszero;
// 	new_string = (char *)malloc(sizeof(char) * length + 1);
// 	i = 0;
// 	while (i < bonuszero)
// 		new_string[i++] = '0';
// 	while (str[i - bonuszero] != '\0')
// 	{
// 		new_string[i] = str[i - bonuszero];
// 		i++;
// 	}
// 	new_string[i] = '\0';
// 	return (new_string);
// }

// done
// void	print_mag(int mag)
// {
// 	char	*str;
// 	char	*to_print;
// 	int		i;

// 	str = malloc(sizeof(char) * mag + 1);
// 	str[0] = '1';
// 	i = 1;
// 	while (i < mag)
// 	{
// 		str[i] = '0';
// 		i++;
// 	}
// 	str[i] = '\0';
// 	to_print = find_key("numbers_specific.dict", str);
// 	free(str);
// 	ft_putstr(to_print);
// 	free(to_print);
// }

// DONE
// int	hundreds(char hundred, int before)
// {
// 	if (hundred != '0')
// 	{
// 		if (before == 1)
// 		{
// 			write(1, " ", 1);
// 		}
// 		print_nb('0', hundred);
// 		write(1, " ", 1);
// 		print_mag(3);
// 		return (1);
// 	}
// 	return (before);
// }

// // DONE
// int	decimals(char decimal, char unity, int before)
// {
// 	int	sum;

// 	sum = (decimal - '0') * 10 + (unity - '0');
// 	if (sum == 0)
// 		return (before);
// 	if (sum < 21)
// 	{
// 		if (before == 1)
// 			write(1, " ", 1);
// 		print_nb(decimal, unity);
// 		return (1);
// 	}
// 	else
// 	{
// 		if (before == 1)
// 			write(1, " ", 1);
// 		print_nb(decimal, '0');
// 		if (unity != 0)
// 		{
// 			write(1, " ", 1);
// 			print_nb('0', unity);
// 		}
// 	}
// 	return (before);
// }

// // DONE
// int	main(int argc, char **argv)
// {
// 	char	*array;
// 	int		mag;
// 	int		length;
// 	int		i;
// 	int		before;

// 	array = correctlength(argv[argc - 1]);
// 	length = ft_strlen(array);
// 	mag = length - 2;
// 	i = 0;
// 	before = 0;
// 	while (i < length)
// 	{
// 		before = hundreds(array[i], before);
// 		before = decimals(array[i + 1], array[i + 2], before);
// 		if (mag > 3)
// 		{
// 			write(1, " ", 1);
// 			print_mag(mag);
// 		}
// 		mag = mag - 3;
// 		i = i + 3;
// 	}
// 	write(1, "\n", 1);
// }

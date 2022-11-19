#ifndef RUSH02_H
# define RUSH02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# define LINE_MAX_LENGTH 100

int		ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	ft_itoa(int n);
void	ft_putstr(char *str);
char	*build_number(char a, char b);
void	print_mag(int mag);
char	*ft_str_dup_printable(char *src);
void	read_line(char *buf, int file_descriptor, int *done);
int		match_nbr(char *str, char *to_find);
char	*find_key(char *file, char *key);
int		ft_str_is_printable(char *str);
void	print_nb(char a, char b);
char	*correctlength(char *str);

#endif





// int		ft_strlen(char *str);
// int		ft_strncmp(char *s1, char *s2, unsigned int n);
// char	ft_itoa(int n);
// void	ft_putstr(char *str);
// char	*build_number(char a, char b);
// char	*ft_mag(int length);
// char	*ft_str_dup_printable(char *src);
// void	read_line(char *buf, int file_descriptor, int *done);
// int		match_nbr(char *str, char *to_find);
// char	*find_key(char *file, char *key);
// int		ft_str_is_printable(char *str);

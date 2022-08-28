#include <unistd.h>

void	ft_deletechar(* str, char eraser)
{
	int	i;

	i = 0;
	eraser = -1;
	while (str[i])
	{
		if (str[i] == eraser)
			str[i] == eraser;
		i++;
	}
}

int main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		while (argv[1][i])
		
			eraser = argv[1][i];
			ft_deletechar (argv[1], eraser);
			ft_deletechar (argv[2], eraser);
			i++;
		}
		
		while (argv[2][i])
		{
			i++;
		}
	}
	return (0);
}


Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
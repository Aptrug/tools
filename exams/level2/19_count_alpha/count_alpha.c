/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   count_alpha.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 21:53:02 by ysabraou                                 */
/*   Updated: 2026/07/12 21:53:02 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	count_chars(char *str, int *count)
{
	int	i;
	int	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			count[c + 32]++;
		else if (c >= 'a' && c <= 'z')
			count[c]++;
		i++;
	}
}

void	print_chars(char *str, int *count)
{
	int	i;
	int	c;
	int	first;

	i = 0;
	first = 1;
	while (str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			c += 32;
		if (c >= 'a' && c <= 'z' && count[c] > 0)
		{
			if (!first)
				printf(", ");
			printf("%d%c", count[c], c);
			count[c] = 0;
			first = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	count[256];
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (i < 256)
		{
			count[i] = 0;
			i++;
		}
		count_chars(argv[1], count);
		print_chars(argv[1], count);
	}
	printf("\n");
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

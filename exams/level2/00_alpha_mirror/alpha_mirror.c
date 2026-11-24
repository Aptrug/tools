/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   alpha_mirror.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:23:58 by ysabraou                                 */
/*   Updated: 2026/07/11 14:23:58 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	mirror(char c)
{
	if (c >= 'a' && c <= 'z')
		return ('z' - (c - 'a'));
	if (c >= 'A' && c <= 'Z')
		return ('Z' - (c - 'A'));
	return (c);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		c = mirror(argv[1][i]);
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

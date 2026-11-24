/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ulstr.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:23:41 by ysabraou                                 */
/*   Updated: 2026/07/11 14:23:41 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	swap_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
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
		c = swap_case(argv[1][i]);
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

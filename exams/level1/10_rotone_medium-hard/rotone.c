/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rotone.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:23:07 by ysabraou                                 */
/*   Updated: 2026/07/11 14:23:07 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	rot_one(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a' + 1) % 26 + 'a');
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A' + 1) % 26 + 'A');
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
		c = rot_one(argv[1][i]);
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

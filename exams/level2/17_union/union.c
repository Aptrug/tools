/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   union.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:30 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:30 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int				seen[256];
	int				i;
	unsigned char	c;

	i = 0;
	while (i < 256)
		seen[i++] = 0;
	++argv;
	while (argc == 3 && argv[0])
	{
		i = 0;
		while (argv[0][i])
		{
			c = argv[0][i];
			if (!seen[c])
			{
				write(1, &c, 1);
				seen[c] = 1;
			}
			++i;
		}
		++argv;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

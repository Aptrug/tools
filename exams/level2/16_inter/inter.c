/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   inter.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:22 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:22 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	inter(char *s1, char *s2)
{
	unsigned char	lookup[256];
	unsigned char	c;
	int				i;

	i = 0;
	while (i < 256)
		lookup[i++] = 0;
	i = 0;
	while (s2[i])
	{
		c = s2[i++];
		lookup[c] = 1;
	}
	i = 0;
	while (s1[i])
	{
		c = s1[i];
		if (lookup[c] == 1)
		{
			write(1, &c, 1);
			lookup[c] = 0;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

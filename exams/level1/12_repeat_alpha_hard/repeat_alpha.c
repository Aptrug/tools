/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   repeat_alpha.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:22:16 by ysabraou                                 */
/*   Updated: 2026/07/11 14:22:16 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	repeat;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat = argv[1][i] - 'a' + 1;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				repeat = argv[1][i] - 'A' + 1;
			else
				repeat = 1;
			while (repeat--)
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

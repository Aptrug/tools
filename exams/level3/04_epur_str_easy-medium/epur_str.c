/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   epur_str.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:21 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:21 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	epur_str(char *str)
{
	int	i;
	int	pending_space;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	pending_space = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			pending_space = 1;
		else
		{
			if (pending_space)
				write(1, " ", 1);
			pending_space = 0;
			write(1, &str[i], 1);
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

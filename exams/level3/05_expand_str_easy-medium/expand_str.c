/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   expand_str.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:38 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:38 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	expand_str(char *str)
{
	int	i;
	int	space_flag;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		++i;
	space_flag = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			space_flag = 1;
		else
		{
			if (space_flag)
				write(1, "   ", 3);
			space_flag = 0;
			write(1, &str[i], 1);
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/* vim: set noet ts=4 sw=4 tw=80 : */

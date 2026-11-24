/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   last_word.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:21:59 by ysabraou                                 */
/*   Updated: 2026/07/11 14:21:59 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	end;
	int	start;

	if (argc == 2)
	{
		end = 0;
		while (argv[1][end])
			end++;
		end--;
		while (end >= 0 && (argv[1][end] == ' ' || argv[1][end] == '\t'))
			end--;
		start = end;
		while (start > 0 && argv[1][start - 1] != ' '
			&& argv[1][start - 1] != '\t')
			start--;
		if (end >= 0)
			write(1, argv[1] + start, end - start + 1);
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

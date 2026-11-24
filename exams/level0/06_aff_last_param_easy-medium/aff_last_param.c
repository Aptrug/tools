/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   aff_last_param.c                                                         */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:56:42 by ysabraou                                 */
/*   Updated: 2026/07/11 13:56:42 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc > 1)
	{
		str = argv[argc - 1];
		while (*str)
		{
			write(1, str, 1);
			++str;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

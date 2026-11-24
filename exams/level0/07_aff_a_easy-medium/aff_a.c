/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   aff_a.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:56:59 by ysabraou                                 */
/*   Updated: 2026/07/11 13:56:59 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*s;

	if (argc != 2)
	{
		write(1, "a\n", 2);
		return (0);
	}
	s = argv[1];
	while (*s && *s != 'a')
		++s;
	if (*s == 'a')
		write(1, "a", 1);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

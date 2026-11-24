/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   hidenp.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:31:20 by ysabraou                                 */
/*   Updated: 2026/07/11 14:31:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_hidden(char *s1, char *s2)
{
	while (*s2)
	{
		while (*s2 == *s1)
			++s1;
		if (*s1 == '\0')
			return (1);
		++s2;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (is_hidden(argv[1], argv[2]))
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rot_13.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:22:50 by ysabraou                                 */
/*   Updated: 2026/07/11 14:22:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char	rot_13(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a' + 13) % 26 + 'a');
	if (c >= 'A' && c <= 'Z')
		return ((c - 'A' + 13) % 26 + 'A');
	return (c);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c;
	char	*str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	str = argv[1];
	while (str[i])
	{
		c = rot_13(str[i]);
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

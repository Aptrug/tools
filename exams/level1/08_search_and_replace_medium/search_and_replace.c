/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   search_and_replace.c                                                     */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:23:24 by ysabraou                                 */
/*   Updated: 2026/07/11 14:23:24 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	arguments_are_invalid(int argc, char *argv[])
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	if (argv[2][0] == '\0' || argv[2][1] != '\0' || argv[3][0] == '\0'
		|| argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	char	*text;
	char	search_char;
	char	replace_char;
	int		i;

	if (arguments_are_invalid(argc, argv))
		return (0);
	text = argv[1];
	search_char = argv[2][0];
	replace_char = argv[3][0];
	i = 0;
	while (text[i] != '\0')
	{
		if (text[i] == search_char)
			text[i] = replace_char;
		++i;
	}
	write(1, text, i);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

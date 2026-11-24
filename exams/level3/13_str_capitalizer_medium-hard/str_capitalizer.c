/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   str_capitalizer.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:33:02 by ysabraou                                 */
/*   Updated: 2026/07/11 14:33:02 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

void	capitalize(char *str)
{
	int		start_of_str;
	char	c;

	start_of_str = 1;
	while (*str)
	{
		if (is_space(*str))
		{
			write(1, str, 1);
			start_of_str = 1;
		}
		else
		{
			if (start_of_str)
				c = to_upper(*str);
			else
				c = to_lower(*str);
			write(1, &c, 1);
			start_of_str = 0;
		}
		++str;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			capitalize(argv[i]);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

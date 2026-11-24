/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rstr_capitalizer.c                                                       */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:32:45 by ysabraou                                 */
/*   Updated: 2026/07/11 14:32:45 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	change_case(char c, int up)
{
	if (up && c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	if (!up && c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

void	rstr_capitalizer(char *str)
{
	char	*ptr;
	char	c;

	while (*str)
	{
		c = change_case(*str, 0);
		if (c >= 'a' && c <= 'z')
		{
			ptr = str + 1;
			while (*ptr && !is_space(*ptr) && !is_alpha(*ptr))
				++ptr;
			if (is_space(*ptr) || *ptr == '\0')
				c = change_case(c, 1);
		}
		write(1, &c, 1);
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
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

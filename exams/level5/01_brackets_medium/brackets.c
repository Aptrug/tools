/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brackets.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 09:38:29 by ysabraou                                 */
/*   Updated: 2026/07/12 09:45:02 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_if_brackets_are_valid(char *str)
{
	int	i;
	int	top;

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			str[top++] = str[i];
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (top == 0 || (str[i] - str[top - 1] < 1)
				|| (str[i] - str[top - 1] > 2))
				return (0);
			--top;
		}
		++i;
	}
	return (top == 0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (*(++argv))
	{
		if (check_if_brackets_are_valid(*argv))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

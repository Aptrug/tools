/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   jumps.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 12:33:47 by ysabraou                                 */
/*   Updated: 2026/07/12 12:47:22 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "brainfuck.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	find_matching_close(char *code, int pos)
{
	int	depth;

	depth = 1;
	++pos;
	while (depth > 0)
	{
		if (code[pos] == '[')
			++depth;
		else if (code[pos] == ']')
			--depth;
		if (depth > 0)
			++pos;
	}
	return (pos);
}

int	find_matching_open(char *code, int pos)
{
	int	depth;

	depth = 1;
	--pos;
	while (depth > 0)
	{
		if (code[pos] == ']')
			++depth;
		else if (code[pos] == '[')
			--depth;
		if (depth > 0)
			--pos;
	}
	return (pos);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

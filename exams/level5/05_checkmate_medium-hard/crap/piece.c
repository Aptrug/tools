/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   piece.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 14:56:00 by ysabraou                                 */
/*   Updated: 2026/07/12 15:16:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "checkmate.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		++len;
	return (len);
}

int	find_king(t_board *b)
{
	int	y;
	int	x;

	y = 0;
	while (y < b->size)
	{
		x = 0;
		while (b->rows[y][x])
		{
			if (b->rows[y][x] == 'K')
			{
				b->ky = y;
				b->kx = x;
				return (1);
			}
			++x;
		}
		++y;
	}
	return (0);
}

int	is_piece(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	slide_check(t_board *b, int dy, int dx, char *targets)
{
	int		y;
	int		x;
	char	c;

	y = b->ky + dy;
	x = b->kx + dx;
	while (y >= 0 && y < b->size && x >= 0 && x < ft_strlen(b->rows[y]))
	{
		c = b->rows[y][x];
		if (is_piece(c, "PBRQ"))
			return (is_piece(c, targets));
		y = y + dy;
		x = x + dx;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

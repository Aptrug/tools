/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   flood_fill.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:33:36 by ysabraou                                 */
/*   Updated: 2026/07/11 14:44:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "flood_fill.h"

int	is_valid(t_point size, t_point p)
{
	return (p.x >= 0 && p.x < size.x && p.y >= 0 && p.y < size.y);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;
	t_point	next;

	if (!is_valid(size, begin))
		return ;
	target = tab[begin.y][begin.x];
	if (target == 'F')
		return ;
	tab[begin.y][begin.x] = 'F';
	next.x = begin.x + 1;
	next.y = begin.y;
	if (is_valid(size, next) && tab[next.y][next.x] == target)
		flood_fill(tab, size, next);
	next.x = begin.x - 1;
	next.y = begin.y;
	if (is_valid(size, next) && tab[next.y][next.x] == target)
		flood_fill(tab, size, next);
	next.x = begin.x;
	next.y = begin.y + 1;
	if (is_valid(size, next) && tab[next.y][next.x] == target)
		flood_fill(tab, size, next);
	next.x = begin.x;
	next.y = begin.y - 1;
	if (is_valid(size, next) && tab[next.y][next.x] == target)
		flood_fill(tab, size, next);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

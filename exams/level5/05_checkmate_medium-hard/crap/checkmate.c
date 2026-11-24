/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   checkmate.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 14:57:00 by ysabraou                                 */
/*   Updated: 2026/07/12 15:17:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "checkmate.h"

int	pawn_check(t_board *b)
{
	int	y;
	int	x1;
	int	x2;

	y = b->ky - 1;
	if (y < 0)
		return (0);
	x1 = b->kx - 1;
	x2 = b->kx + 1;
	if (x1 >= 0 && x1 < ft_strlen(b->rows[y]) && b->rows[y][x1] == 'P')
		return (1);
	if (x2 >= 0 && x2 < ft_strlen(b->rows[y]) && b->rows[y][x2] == 'P')
		return (1);
	return (0);
}

int	is_check(t_board *b)
{
	if (slide_check(b, -1, 0, "RQ") || slide_check(b, 1, 0, "RQ")
		|| slide_check(b, 0, -1, "RQ") || slide_check(b, 0, 1, "RQ"))
		return (1);
	if (slide_check(b, -1, -1, "BQ") || slide_check(b, -1, 1, "BQ")
		|| slide_check(b, 1, -1, "BQ") || slide_check(b, 1, 1, "BQ"))
		return (1);
	return (pawn_check(b));
}

int	main(int argc, char **argv)
{
	t_board	board;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	board.rows = argv + 1;
	board.size = argc - 1;
	if (!find_king(&board) || !is_check(&board))
		write(1, "Fail\n", 5);
	else
		write(1, "Success\n", 8);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

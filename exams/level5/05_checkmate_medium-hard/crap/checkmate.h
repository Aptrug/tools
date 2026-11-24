/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   checkmate.h                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 14:55:00 by ysabraou                                 */
/*   Updated: 2026/07/12 15:15:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKMATE_H
# define CHECKMATE_H

typedef struct s_board
{
	char	**rows;
	int		size;
	int		kx;
	int		ky;
}	t_board;

int	ft_strlen(char *s);
int	find_king(t_board *b);
int	is_piece(char c, char *set);
int	slide_check(t_board *b, int dy, int dx, char *targets);
int	pawn_check(t_board *b);
int	is_check(t_board *b);

#endif
/* vim: set noet ts=4 sw=4 tw=80 : */

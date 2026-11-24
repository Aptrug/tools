/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   flood_fill.h                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:33:53 by ysabraou                                 */
/*   Updated: 2026/07/11 14:44:05 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin);

#endif
/* vim: set noet ts=4 sw=4 tw=80 : */

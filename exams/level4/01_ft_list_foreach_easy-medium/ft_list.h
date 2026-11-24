/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_list.h                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:35:01 by ysabraou                                 */
/*   Updated: 2026/07/11 14:41:30 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif
/* vim: set noet ts=4 sw=4 tw=80 : */

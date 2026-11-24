/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_list_foreach.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:34:44 by ysabraou                                 */
/*   Updated: 2026/07/11 14:41:45 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */

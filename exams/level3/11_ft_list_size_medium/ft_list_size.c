/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_list_size.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:30:12 by ysabraou                                 */
/*   Updated: 2026/07/11 14:30:12 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		++size;
		begin_list = begin_list->next;
	}
	return (size);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

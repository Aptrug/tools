/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_list_remove_if.c                                                      */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:35:18 by ysabraou                                 */
/*   Updated: 2026/07/11 14:50:12 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;

	while (*begin_list)
	{
		if (!cmp((*begin_list)->data, data_ref))
		{
			temp = (*begin_list);
			*begin_list = temp->next;
			free(temp);
		}
		else
			begin_list = &(*begin_list)->next;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */

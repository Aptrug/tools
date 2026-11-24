/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 09:16:02 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/31 09:16:02 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*sorted_list;
	t_list	*tmp_next;
	t_list	**insert_ptr;

	sorted_list = 0;
	while (lst)
	{
		tmp_next = lst->next;
		insert_ptr = &sorted_list;
		while (*insert_ptr && !cmp(lst->data, (*insert_ptr)->data))
			insert_ptr = &(*insert_ptr)->next;
		lst->next = *insert_ptr;
		*insert_ptr = lst;
		lst = tmp_next;
	}
	return (sorted_list);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

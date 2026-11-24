/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 09:17:55 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/31 09:17:55 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}	t_list;

#endif
/* vim: set noet ts=4 sw=4 tw=80 : */

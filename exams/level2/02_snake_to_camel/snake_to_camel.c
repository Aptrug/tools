/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:38:59 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/23 17:38:59 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_camel(char *str)
{
	int	capitalize_next;

	capitalize_next = 0;
	while (*str)
	{
		if (*str == '_')
			capitalize_next = 1;
		else
		{
			if (capitalize_next)
			{
				*str -= 32;
				capitalize_next = 0;
			}
			write(1, str, 1);
		}
		++str;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_camel(argv[1]);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

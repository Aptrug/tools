/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 11:58:48 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/30 11:58:48 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char *str)
{
	char	*ptr;

	ptr = str;
	while (*str)
		++str;
	return (str - ptr);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	*ptr;
	char	*end;

	if (argc == 2 && argv[1][0] != '\0')
	{
		str = argv[1];
		ptr = str + ft_strlen(str) - 1;
		while (ptr >= str && is_space(*ptr))
			--ptr;
		while (ptr >= str)
		{
			end = ptr;
			while (ptr >= str && !is_space(*ptr))
				--ptr;
			write(1, ptr + 1, end - ptr);
			while (ptr >= str && is_space(*ptr))
				--ptr;
			if (ptr >= str)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 00:20:52 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/17 00:20:52 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		len;
	int		i;
	char	tmp;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		len = 0;
		while (str[len])
			len++;
		i = 0;
		while (i < len / 2)
		{
			tmp = str[i];
			str[i] = str[len - 1 - i];
			str[len - 1 - i] = tmp;
			i++;
		}
		write(1, str, len);
	}
	write(1, "\n", 1);
	return (0);
}

/*
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		while (*str)
			++str;
		--str;
		while (str >= argv[1])
			write(1, str--, 1);
	}
	write(1, "\n", 1);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 18:24:06 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/30 18:24:06 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_sep(char c)
{
	return (c == ' ' || c == '\t');
}

int	collapse_rest(char *s, int i, char *buf)
{
	int	len;

	len = 0;
	while (s[i])
	{
		while (is_sep(s[i]))
			i++;
		if (s[i] && len != 0)
			buf[len++] = ' ';
		while (s[i] && !is_sep(s[i]))
			buf[len++] = s[i++];
	}
	return (len);
}

int	find_first_word(char *s, int *start)
{
	int	i;

	i = 0;
	while (is_sep(s[i]))
		i++;
	*start = i;
	while (s[i] && !is_sep(s[i]))
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	buf[4096];
	char	*s;
	int		end;
	int		len;
	int		start;

	if (argc != 2)
		return (write(1, "\n", 1), 0);
	s = argv[1];
	end = find_first_word(s, &start);
	if (start == end)
		return (write(1, "\n", 1), 0);
	len = collapse_rest(s, end, buf);
	if (len > 0)
	{
		write(1, buf, len);
		write(1, " ", 1);
	}
	write(1, s + start, end - start);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

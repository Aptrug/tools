/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::  */
/*   rostring.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2026/07/30 09:29:38 by student           #+#    #+#           */
/*   Updated: 2026/07/30 09:29:38 by student          ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_sep(char c)
{
	return (c == ' ' || c == '\t');
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

void	print_word(char *s, int *i)
{
	while (is_sep(s[*i]))
		(*i)++;
	while (s[*i] && !is_sep(s[*i]))
		write(1, &s[(*i)++], 1);
}

void	print_rest(char *s, int i)
{
	int	printed;

	printed = 0;
	while (s[i])
	{
		while (is_sep(s[i]))
			i++;
		if (s[i])
		{
			if (printed)
				write(1, " ", 1);
			print_word(s, &i);
			printed = 1;
		}
	}
	if (printed)
		write(1, " ", 1);
}

int	main(int argc, char **argv)
{
	char	*s;
	int		i;
	int		start;

	if (argc != 2)
		return (write(1, "\n", 1), 0);
	s = argv[1];
	i = find_first_word(s, &start);
	if (start == i)
		return (write(1, "\n", 1), 0);
	print_rest(s, i);
	i = start;
	print_word(s, &i);
	write(1, "\n", 1);
	return (0);
}

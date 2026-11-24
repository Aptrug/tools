/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:38:45 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/30 13:38:45 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_space(*str))
			++str;
		if (*str)
			++count;
		while (*str && !is_space(*str))
			++str;
	}
	return (count);
}

char	*copy_word(char *str, int len)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	*start;
	char	**res;
	char	**ptr;

	res = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!res)
		return (NULL);
	ptr = res;
	while (*str)
	{
		while (*str && is_space(*str))
			++str;
		if (*str)
		{
			start = str;
			while (*str && !is_space(*str))
				++str;
			*ptr = copy_word(start, str - start);
			++ptr;
		}
	}
	*ptr = NULL;
	return (res);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

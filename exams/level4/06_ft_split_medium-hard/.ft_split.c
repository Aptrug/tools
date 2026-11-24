/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_split.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:35:52 by ysabraou                                 */
/*   Updated: 2026/07/11 14:43:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			++i;
		if (str[i])
			++count;
		while (str[i] && !is_space(str[i]))
			++i;
	}
	return (count);
}

char	*extract_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		++i;
		++start;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**result;
	int		i;
	int		w;
	int		start;

	result = malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	i = 0;
	w = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			++i;
		start = i;
		while (str[i] && !is_space(str[i]))
			++i;
		if (i > start)
			result[w++] = extract_word(str, start, i);
	}
	result[w] = NULL;
	return (result);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

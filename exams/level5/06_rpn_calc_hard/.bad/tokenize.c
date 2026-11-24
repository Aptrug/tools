/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tokenize.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 11:42:15 by ysabraou                                 */
/*   Updated: 2026/07/12 12:07:44 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "rpn_calc.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	count_tokens(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		if (str[i])
			++count;
		while (str[i] && str[i] != ' ')
			++i;
	}
	return (count);
}

char	*extract_token(char *str, int start, int end)
{
	char	*token;
	int		i;

	token = malloc(sizeof(char) * (end - start + 1));
	if (!token)
		return (NULL);
	i = 0;
	while (start < end)
	{
		token[i] = str[start];
		++i;
		++start;
	}
	token[i] = '\0';
	return (token);
}

char	**tokenize(char *str, int *count)
{
	char	**tokens;
	int		i;
	int		t;
	int		start;

	*count = count_tokens(str);
	tokens = malloc(sizeof(char *) * (*count));
	if (!tokens)
		return (NULL);
	i = 0;
	t = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			++i;
		start = i;
		while (str[i] && str[i] != ' ')
			++i;
		if (i > start)
			tokens[t++] = extract_token(str, start, i);
	}
	return (tokens);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

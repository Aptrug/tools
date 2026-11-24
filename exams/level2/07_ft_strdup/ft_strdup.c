/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strdup.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:25:57 by ysabraou                                 */
/*   Updated: 2026/07/11 14:25:57 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	str_len(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * (str_len(src) + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

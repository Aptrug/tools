/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcspn.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:25:40 by ysabraou                                 */
/*   Updated: 2026/07/11 14:25:40 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	unsigned char	set[256];
	size_t			i;

	i = 0;
	while (i < 256)
		set[i++] = 0;
	while (*reject)
		set[(unsigned char)*reject++] = 1;
	i = 0;
	while (s[i] && !set[(unsigned char)s[i]])
		++i;
	return (i);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

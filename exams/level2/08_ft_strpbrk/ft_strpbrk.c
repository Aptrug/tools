/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strpbrk.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:26:14 by ysabraou                                 */
/*   Updated: 2026/07/11 14:26:14 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	unsigned char	set[256];
	size_t			i;

	i = 0;
	while (i < 256)
		set[i++] = 0;
	while (*s2)
		set[(unsigned char)*s2++] = 1;
	while (*s1)
	{
		if (set[(unsigned char)*s1])
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

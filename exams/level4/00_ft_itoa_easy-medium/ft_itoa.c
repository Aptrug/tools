/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_itoa.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:34:27 by ysabraou                                 */
/*   Updated: 2026/07/11 14:41:12 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#define BUFSZ 11

char	*ft_itoa(int nbr)
{
	char	buf[BUFSZ];
	char	*ptr;
	char	*res;
	int		len;
	long	n;

	n = nbr;
	if (n < 0)
		n = -n;
	ptr = buf + BUFSZ;
	while (ptr == buf + BUFSZ || n > 0)
	{
		*(--ptr) = (n % 10) + '0';
		n /= 10;
	}
	if (nbr < 0)
		*(--ptr) = '-';
	len = buf + BUFSZ - ptr;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len-- > 0)
		res[len] = ptr[len];
	return (res);
}

/*
int	main(void)
{
	char	*str;
	str = ft_itoa(42);
	free(str);

	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */

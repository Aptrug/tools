/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fizzbuzz.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:20:34 by ysabraou                                 */
/*   Updated: 2026/07/11 14:20:34 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_nbr(int n)
{
	char	buf[3];
	char	*ptr;

	ptr = buf + sizeof(buf);
	while (n > 0 || ptr == buf + sizeof(buf))
	{
		*(--ptr) = n % 10 + '0';
		n /= 10;
	}
	write(1, ptr, buf + sizeof(buf) - ptr);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			put_nbr(i);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   paramsum.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:31:54 by ysabraou                                 */
/*   Updated: 2026/07/11 14:31:54 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_nbr(int n)
{
	char	buf[10];
	char	*ptr;

	ptr = buf + 10 - 1;
	*ptr = (n % 10) + '0';
	while (n > 9)
	{
		n /= 10;
		*(--ptr) = (n % 10) + '0';
	}
	write(1, ptr, buf + 10 - ptr);
}

int	main(int argc, char **argv)
{
	(void)argv;
	put_nbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

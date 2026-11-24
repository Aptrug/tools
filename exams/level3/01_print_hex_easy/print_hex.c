/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print_hex.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:32:28 by ysabraou                                 */
/*   Updated: 2026/07/11 14:32:28 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

#define BUFSZ 32

void	print_hex(unsigned int n)
{
	char	*hex_base;
	char	buf[BUFSZ];
	char	*ptr;

	hex_base = "0123456789abcdef";
	ptr = buf + BUFSZ;
	while (n > 0 || ptr == buf + BUFSZ)
	{
		*(--ptr) = hex_base[n % 16];
		n = n / 16;
	}
	write(1, ptr, buf + BUFSZ - ptr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   add_prime_sum.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:04 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:04 by ysabraou                                 */
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

int	str_to_nbr(char *str)
{
	int	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		++str;
	}
	return (n);
}

int	is_prime(int n)
{
	int	i;

	if (n <= 1)
		return (0);
	i = 2;
	while (i <= n / i)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	limit;
	int	sum;
	int	i;

	sum = 0;
	if (argc == 2)
	{
		limit = str_to_nbr(argv[1]);
		if (limit != 0)
		{
			i = 2;
			while (i <= limit)
			{
				if (is_prime(i))
					sum = sum + i;
				++i;
			}
		}
	}
	put_nbr(sum);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 19:16:38 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/21 19:16:38 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_nbr(int n)
{
	char	buf[10];
	int		i;

	i = 10;
	while (n > 0 || i == 10)
	{
		buf[--i] = (n % 10) + '0';
		n /= 10;
	}
	write(1, buf + i, 10 - i);
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

int	main(int argc, char **argv)
{
	int	nbr;
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	nbr = str_to_nbr(argv[1]);
	i = 1;
	while (i <= 9)
	{
		put_nbr(i);
		write(1, " x ", 3);
		put_nbr(nbr);
		write(1, " = ", 3);
		put_nbr(i * nbr);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:50:37 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/29 19:50:37 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	build_map(int *map)
{
	int	i;

	i = -1;
	while (++i < 256)
	{
		if (i >= '0' && i <= '9')
			map[i] = i - '0';
		else if (i >= 'a' && i <= 'f')
			map[i] = i - 'a' + 10;
		else if (i >= 'A' && i <= 'F')
			map[i] = i - 'A' + 10;
		else
			map[i] = -1;
	}
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	map[256];
	int	res;
	int	sign;

	build_map(map);
	res = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
		sign = 1;
	while (map[(unsigned char)*str] != -1)
	{
		res = (res * str_base) + map[(unsigned char)*str];
		++str;
	}
	return (res * sign);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

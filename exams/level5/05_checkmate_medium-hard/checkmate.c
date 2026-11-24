/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 20:38:31 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/05 20:38:31 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	is_piece(char c)
{
	return (c == 'P' || c == 'B' || c == 'R' || c == 'Q');
}

int	check_ray(char **board, int size, int kx, int ky, int dx, int dy)
{
	int x = kx + dx;
	int y = ky + dy;
	int dist = 1;

	while (x >= 0 && x < size && y >= 0 && y < size)
	{
		if (is_piece(board[y][x]))
		{
			if (board[y][x] == 'Q')
				return (1);
			if (board[y][x] == 'R' && (dx == 0 || dy == 0))
				return (1);
			if (board[y][x] == 'B' && (dx != 0 && dy != 0))
				return (1);
			if (board[y][x] == 'P' && dist == 1 && dy == -1
				&& (dx == 1 || dx == -1))
				return (1);

			return (
				0); /* Ray blocked by a piece that cannot capture in this direction */
		}
		x += dx;
		y += dy;
		dist++;
	}
	return (0);
}

int	checkmate(char **board, int size)
{
	int	i, j, kx, ky, d;
	int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

	kx = -1;
	ky = -1;

	/* Find the King */
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (board[i][j] == 'K')
			{
				kx = j;
				ky = i;
				break ;
			}
		}
	}

	if (kx == -1)
		return (0);

	/* Cast a ray in all 8 directions from the King */
	d = 0;
	while (++d)
	{
		if (check_ray(board, size, kx, ky, dx[d], dy[d]))
			return (1);
		++d;
	}

	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (checkmate(argv + 1, argc - 1))
			ft_putstr("Success\n");
		else
			ft_putstr("Fail\n");
	}
	else
	{
		write(1, "\n", 1);
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

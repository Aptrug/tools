/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   pgcd.c                                                                   */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:32:11 by ysabraou                                 */
/*   Updated: 2026/07/11 14:32:11 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	pgcd(int a, int b)
{
	int	remainder;

	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	printf("%d\n", pgcd(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

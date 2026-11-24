/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fprime.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:34:10 by ysabraou                                 */
/*   Updated: 2026/07/11 14:42:03 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	if (argc == 2)
	{
		i = 2;
		n = atoi(argv[1]);
		if (n == 1)
			printf("1");
		while (n > 1)
		{
			if (n % i == 0)
			{
				printf("%d", i);
				n /= i;
				if (n > 1)
					printf("*");
			}
			else
				++i;
		}
	}
	printf("\n");
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

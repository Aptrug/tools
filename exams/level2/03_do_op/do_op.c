/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   do_op.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:24:32 by ysabraou                                 */
/*   Updated: 2026/07/11 14:24:32 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "do_op.h"

int	do_op(int a, char op, int b)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
		return (a / b);
	return (a % b);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	a = atoi(argv[1]);
	b = atoi(argv[3]);
	printf("%d\n", do_op(a, argv[2][0], b));
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

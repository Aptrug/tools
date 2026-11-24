/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rpn_calc.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 12:01:47 by ysabraou                                 */
/*   Updated: 2026/07/12 12:19:03 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "rpn_calc.h"

int	main(int argc, char **argv)
{
	int	result;
	int	ok;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	result = eval_rpn(argv[1], &ok);
	if (!ok)
		write(1, "Error\n", 6);
	else
		printf("%d\n", result);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

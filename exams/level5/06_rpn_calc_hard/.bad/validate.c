/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   validate.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 11:50:03 by ysabraou                                 */
/*   Updated: 2026/07/12 12:10:52 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include "rpn_calc.h"

int	is_operator(char *token)
{
	return (ft_strlen(token) == 1 && (token[0] == '+' || token[0] == '-'
			|| token[0] == '*' || token[0] == '/' || token[0] == '%'));
}

int	is_number(char *token)
{
	int	i;

	i = 0;
	if (token[i] == '-')
		++i;
	if (!token[i])
		return (0);
	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
			return (0);
		++i;
	}
	return (1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   eval.c                                                                   */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 11:55:37 by ysabraou                                 */
/*   Updated: 2026/07/12 12:14:29 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "rpn_calc.h"

int	apply_op(int a, int b, char op, int *ok)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (b == 0)
	{
		*ok = 0;
		return (0);
	}
	if (op == '/')
		return (a / b);
	return (a % b);
}

int	eval_rpn(char *str, int *ok)
{
	char	**tokens;
	int		count;
	t_stack	stack;
	int		i;
	int		result;

	tokens = tokenize(str, &count);
	stack.data = malloc(sizeof(int) * (count + 1));
	stack.top = 0;
	*ok = 1;
	i = 0;
	while (i < count && *ok)
	{
		if (is_number(tokens[i]))
			stack.data[stack.top++] = atoi(tokens[i]);
		else if (is_operator(tokens[i]) && stack.top >= 2)
		{
			stack.top = stack.top - 2;
			stack.data[stack.top] = apply_op(stack.data[stack.top],
					stack.data[stack.top + 1], tokens[i][0], ok);
			++stack.top;
		}
		else
			*ok = 0;
		++i;
	}
	if (stack.top != 1)
		*ok = 0;
	result = 0;
	if (*ok)
		result = stack.data[0];
	free(stack.data);
	i = 0;
	while (i < count)
		free(tokens[i++]);
	free(tokens);
	return (result);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

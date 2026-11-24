/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rpn_calc.h                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 11:41:02 by ysabraou                                 */
/*   Updated: 2026/07/12 12:03:18 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef RPN_CALC_H
# define RPN_CALC_H

typedef struct s_stack
{
	int	*data;
	int	top;
}	t_stack;

int	ft_strlen(char *str);
int	is_operator(char *token);
int	is_number(char *token);
int	count_tokens(char *str);
char	**tokenize(char *str, int *count);
int	apply_op(int a, int b, char op, int *ok);
int	eval_rpn(char *str, int *ok);

#endif
/* vim: set noet ts=4 sw=4 tw=80 : */

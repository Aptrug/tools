/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_atoi.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:25:06 by ysabraou                                 */
/*   Updated: 2026/07/11 14:25:06 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	while (is_space(*str))
		++str;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	return (result * sign);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

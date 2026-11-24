/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlen.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:21:25 by ysabraou                                 */
/*   Updated: 2026/07/11 14:21:25 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

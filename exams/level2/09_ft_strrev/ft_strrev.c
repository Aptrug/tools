/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strrev.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:26:31 by ysabraou                                 */
/*   Updated: 2026/07/11 14:26:31 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	str_len(char *str)
{
	char	*s;

	s = str;
	while (*s)
		++s;
	return (s - str);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = str_len(str);
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		++i;
	}
	return (str);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

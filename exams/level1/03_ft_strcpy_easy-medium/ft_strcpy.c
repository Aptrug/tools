/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcpy.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:21:08 by ysabraou                                 */
/*   Updated: 2026/07/11 14:21:08 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = '\0';
	return (s1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   max.c                                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:27:22 by ysabraou                                 */
/*   Updated: 2026/07/11 14:27:22 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				biggest;

	if (len == 0)
		return (0);
	biggest = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > biggest)
			biggest = tab[i];
		++i;
	}
	return (biggest);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

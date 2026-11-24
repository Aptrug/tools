/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort_int_tab.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:36:43 by ysabraou                                 */
/*   Updated: 2026/07/11 14:43:35 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			ft_swap(&tab[j], &tab[j - 1]);
			--j;
		}
		++i;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */

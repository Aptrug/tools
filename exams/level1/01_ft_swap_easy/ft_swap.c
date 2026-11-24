/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_swap.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:21:42 by ysabraou                                 */
/*   Updated: 2026/07/11 14:21:42 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/* vim: set noet ts=4 sw=4 tw=80 : */

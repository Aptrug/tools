/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   is_power_of_2.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:27:05 by ysabraou                                 */
/*   Updated: 2026/07/11 14:27:05 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
/* replace 2 with 3, 4, etc */
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return (n == 1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

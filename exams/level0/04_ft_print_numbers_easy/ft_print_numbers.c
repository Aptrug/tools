/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_numbers.c                                                       */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:56:08 by ysabraou                                 */
/*   Updated: 2026/07/11 13:56:08 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		++c;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */

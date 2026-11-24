/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   maff_revalpha.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:57:50 by ysabraou                                 */
/*   Updated: 2026/07/11 13:57:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(void)
{
	int		i;
	int		should_be_upper;
	char	letter;

	i = 25;
	should_be_upper = 0;
	while (i >= 0)
	{
		if (should_be_upper)
		{
			should_be_upper = 0;
			letter = 'A' + i;
		}
		else
		{
			should_be_upper = 1;
			letter = 'a' + i;
		}
		write(1, &letter, 1);
		--i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

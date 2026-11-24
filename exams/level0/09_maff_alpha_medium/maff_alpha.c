/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   maff_alpha.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:57:33 by ysabraou                                 */
/*   Updated: 2026/07/11 13:57:33 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(void)
{
	int		i;
	char	letter;

	i = 0;
	while (i < 26)
	{
		if (i % 2 == 0)
			letter = 'a' + i;
		else
			letter = 'A' + i;
		write(1, &letter, 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

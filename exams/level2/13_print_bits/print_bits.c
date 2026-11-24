/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print_bits.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:27:39 by ysabraou                                 */
/*   Updated: 2026/07/11 14:27:39 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	buf[8];

	i = 7;
	while (i >= 0)
	{
		buf[7 - i] = '0' + ((octet >> i) & 1);
		--i;
	}
	write(1, buf, 8);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

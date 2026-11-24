/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   reverse_bits.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:27:56 by ysabraou                                 */
/*   Updated: 2026/07/11 14:27:56 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = result << 1 | (octet >> i & 1);
		++i;
	}
	return (result);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

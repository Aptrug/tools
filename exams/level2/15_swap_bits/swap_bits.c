/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   swap_bits.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:13 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:13 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	res;

	res = octet << 4 | octet >> 4;
	return (res);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

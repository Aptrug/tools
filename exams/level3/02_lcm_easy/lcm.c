/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   lcm.c                                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:31:37 by ysabraou                                 */
/*   Updated: 2026/07/11 14:31:37 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
unsigned int	hcf(unsigned int a, unsigned int b)
{
	unsigned int	remainder;

	while (b != 0)
	{
		remainder = a % b;
		a = b;
		b = remainder;
	}
	return (a);
}

/* Divide first to prevent overflow, then multiply */
unsigned int	lcm(unsigned int a, unsigned int b)
{
	if (a == 0 || b == 0)
		return (0);
	return ((a / hcf(a, b)) * b);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_itoa_base.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 09:12:03 by ysabraou                                 */
/*   Updated: 2026/07/12 09:31:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_nbrlen_base(unsigned int nbr, int base, int is_neg)
{
	int	len;

	len = 1;
	if (is_neg)
		++len;
	while (nbr >= (unsigned int)base)
	{
		nbr = nbr / base;
		++len;
	}
	return (len);
}

unsigned int	ft_abs_value(int value, int base, int *is_neg)
{
	*is_neg = 0;
	if (base == 10 && value < 0)
	{
		*is_neg = 1;
		return (-(unsigned int)value);
	}
	return ((unsigned int)value);
}

char	*ft_itoa_base(int value, int base)
{
	char			*str;
	char			*digits;
	int				len;
	int				is_neg;
	unsigned int	nbr;

	digits = "0123456789ABCDEF";
	nbr = ft_abs_value(value, base, &is_neg);
	len = ft_nbrlen_base(nbr, base, is_neg);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (is_neg)
		str[0] = '-';
	while (len > 0 && str[len - 1] != '-')
	{
		--len;
		str[len] = digits[nbr % base];
		nbr = nbr / base;
	}
	return (str);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

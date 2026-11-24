/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_range.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:30:46 by ysabraou                                 */
/*   Updated: 2026/07/11 14:30:46 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*range;
	int	size;
	int	i;
	int	step;

	if (start <= end)
	{
		size = end - start + 1;
		step = 1;
	}
	else
	{
		size = start - end + 1;
		step = -1;
	}
	range = malloc(sizeof(int) * size);
	if (!range)
		return (NULL);
	i = 0;
	while (i < size)
	{
		range[i] = start + i * step;
		++i;
	}
	return (range);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

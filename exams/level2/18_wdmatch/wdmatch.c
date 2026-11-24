/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   wdmatch.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:47 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int len = 0;

	while (str[len])
		len++;
	write(1, str, len);
}

int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];

		/* Advance s1 only on match. s2 always advances. */
		while (*s1 && *s2)
		{
			if (*s1 == *s2)
				s1++;
			s2++;
		}

		/* If s1 reached the null terminator, it's a full match. */
		if (*s1 == '\0')
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

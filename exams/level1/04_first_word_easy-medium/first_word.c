/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   first_word.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:20:17 by ysabraou                                 */
/*   Updated: 2026/07/11 14:20:17 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	*word;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	word = argv[1];
	i = 0;
	while (word[i] == ' ' || word[i] == '\t')
		++i;
	while (word[i] != '\0' && word[i] != ' ' && word[i] != '\t')
	{
		write(1, &word[i], 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

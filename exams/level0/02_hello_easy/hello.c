/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   hello.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:55:34 by ysabraou                                 */
/*   Updated: 2026/07/11 13:55:34 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(void)
{
	write(1, "Hello World!\n", 13);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

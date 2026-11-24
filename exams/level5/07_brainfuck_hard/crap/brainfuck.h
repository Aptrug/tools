/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brainfuck.h                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 12:31:09 by ysabraou                                 */
/*   Updated: 2026/07/12 12:44:57 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#ifndef BRAINFUCK_H
# define BRAINFUCK_H

# define TAPE_SIZE 2048

typedef struct s_bf
{
	unsigned char	*tape;
	int				ptr;
	char			*code;
	int				pc;
}	t_bf;

int	ft_strlen(char *str);
int	find_matching_close(char *code, int pos);
int	find_matching_open(char *code, int pos);
void	exec_instruction(t_bf *bf);
void	brainfuck(char *code);

#endif
/* vim: set noet ts=4 sw=4 tw=80 : */

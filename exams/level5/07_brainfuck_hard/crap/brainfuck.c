/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brainfuck.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 12:36:29 by ysabraou                                 */
/*   Updated: 2026/07/12 12:52:11 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "brainfuck.h"

void	exec_instruction(t_bf *bf)
{
	char	c;

	c = bf->code[bf->pc];
	if (c == '>')
		++bf->ptr;
	else if (c == '<')
		--bf->ptr;
	else if (c == '+')
		++bf->tape[bf->ptr];
	else if (c == '-')
		--bf->tape[bf->ptr];
	else if (c == '.')
		write(1, &bf->tape[bf->ptr], 1);
	else if (c == '[' && bf->tape[bf->ptr] == 0)
		bf->pc = find_matching_close(bf->code, bf->pc);
	else if (c == ']' && bf->tape[bf->ptr] != 0)
		bf->pc = find_matching_open(bf->code, bf->pc);
}

void	brainfuck(char *code)
{
	t_bf	bf;
	int		i;

	bf.tape = malloc(sizeof(unsigned char) * TAPE_SIZE);
	if (!bf.tape)
		return ;
	i = 0;
	while (i < TAPE_SIZE)
		bf.tape[i++] = 0;
	bf.ptr = 0;
	bf.code = code;
	bf.pc = 0;
	while (bf.pc < ft_strlen(code))
	{
		exec_instruction(&bf);
		++bf.pc;
	}
	free(bf.tape);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	brainfuck(argv[1]);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */

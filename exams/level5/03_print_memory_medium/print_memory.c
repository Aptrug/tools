/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 22:33:08 by ysabraou          #+#    #+#             */
/*   Updated: 2026/08/06 22:33:08 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_memory(const void *addr, size_t size)
{
	size_t				i;
	size_t				j;
	const unsigned char	*ptr;
	char				*hex;
	char				c;

	/* Handle edge case where size is 0 */
	if (size == 0)
		return ;

	ptr = (const unsigned char *)addr;
	hex = "0123456789abcdef";

	/* Loop through memory in chunks of 16 bytes */
	for (i = 0; i < size; i += 16)
	{
		/* 1. Print the Hexadecimal representation */
		for (j = 0; j < 16; j++)
		{
			if (i + j < size)
			{
				/* Print byte in 2 hex characters */
				c = hex[ptr[i + j] / 16];
				write(1, &c, 1);
				c = hex[ptr[i + j] % 16];
				write(1, &c, 1);
			}
			else
			{
				/* Pad with spaces if out of bounds */
				write(1, "  ", 2);
			}

			/* Print a space after every 2 bytes (i.e. on odd indexes) */
			if (j % 2 != 0)
			{
				write(1, " ", 1);
			}
		}

		/* 2. Print the ASCII printable characters */
		for (j = 0; j < 16 && (i + j) < size; j++)
		{
			if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
			{
				write(1, &ptr[i + j], 1);
			}
			else
			{
				write(1, ".", 1);
			}
		}

		/* 3. Line break */
		write(1, "\n", 1);
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */

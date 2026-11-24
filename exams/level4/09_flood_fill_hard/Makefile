NAME		= flood_fill
SRC		= $(NAME).c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

test:
	set -e
	mkdir -p $(BUILD_DIR)
	cat > $(BUILD_DIR)/main.c << 'EOF'
	#include <stdlib.h>
	#include <stdio.h>
	#include "flood_fill.h"

	char **make_area(char **zone, t_point size)
	{
		char	**new;
		int		i;
		int		j;

		new = malloc(sizeof(char *) * size.y);
		i = 0;
		while (i < size.y)
		{
			new[i] = malloc(size.x + 1);
			j = 0;
			while (j < size.x)
			{
				new[i][j] = zone[i][j];
				j = j + 1;
			}
			new[i][size.x] = '\0';
			i = i + 1;
		}
		return (new);
	}

	int main(void)
	{
		t_point	size;
		t_point	begin;
		char	*zone[5];
		char	**area;
		int		i;

		size.x = 8;
		size.y = 5;
		zone[0] = "11111111";
		zone[1] = "10001001";
		zone[2] = "10010001";
		zone[3] = "10110001";
		zone[4] = "11100001";
		area = make_area(zone, size);
		begin.x = 7;
		begin.y = 4;
		flood_fill(area, size, begin);
		i = 0;
		while (i < size.y)
		{
			printf("%s\n", area[i]);
			i = i + 1;
		}
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) -I. $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'FFFFFFFF\nF000F00F\nF00F000F\nF0FF000F\nFFF0000F')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: flood_fill output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) flood_fill.h || exit 1
	fi
	echo "PASS: flood_fill"

clean:
	rm -rf $(BUILD_DIR)

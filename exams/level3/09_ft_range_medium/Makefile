NAME		= ft_range
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
	#include <stdio.h>
	#include <stdlib.h>
	int *ft_range(int start, int end);

	static void print_range(int start, int end)
	{
		int	*r;
		int	size;
		int	i;
		int	step;

		r = ft_range(start, end);
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
		i = 0;
		while (i < size)
		{
			if (i > 0)
				printf(" ");
			printf("%d", r[i]);
			i = i + 1;
		}
		printf("\n");
		free(r);
		(void)step;
	}

	int main(void)
	{
		print_range(1, 3);
		print_range(-1, 2);
		print_range(0, 0);
		print_range(0, -3);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '1 2 3\n-1 0 1 2\n0\n0 -1 -2 -3')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_range output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_range"

clean:
	rm -rf $(BUILD_DIR)

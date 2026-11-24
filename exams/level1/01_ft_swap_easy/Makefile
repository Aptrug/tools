NAME		= ft_swap
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
	void ft_swap(int *a, int *b);

	int main(void)
	{
		int	a;
		int	b;

		a = 1;
		b = 2;
		ft_swap(&a, &b);
		printf("%d %d\n", a, b);
		a = -5;
		b = 5;
		ft_swap(&a, &b);
		printf("%d %d\n", a, b);
		a = 0;
		b = 0;
		ft_swap(&a, &b);
		printf("%d %d\n", a, b);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '2 1\n5 -5\n0 0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_swap output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_swap"

clean:
	rm -rf $(BUILD_DIR)

NAME		= ft_itoa_base
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
	#include <limits.h>
	char *ft_itoa_base(int value, int base);

	int main(void)
	{
		printf("%s\n", ft_itoa_base(0, 10));
		printf("%s\n", ft_itoa_base(42, 10));
		printf("%s\n", ft_itoa_base(-42, 10));
		printf("%s\n", ft_itoa_base(255, 16));
		printf("%s\n", ft_itoa_base(255, 2));
		printf("%s\n", ft_itoa_base(6, 4));
		printf("%s\n", ft_itoa_base(-1, 16));
		printf("%s\n", ft_itoa_base(-42, 16));
		printf("%s\n", ft_itoa_base(INT_MAX, 10));
		printf("%s\n", ft_itoa_base(INT_MIN, 10));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '0\n42\n-42\nFF\n11111111\n12\nFFFFFFFF\nFFFFFFD6\n2147483647\n-2147483648')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_itoa_base output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_itoa_base"

clean:
	rm -rf $(BUILD_DIR)

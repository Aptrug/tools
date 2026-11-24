NAME		= ft_atoi
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

	int ft_atoi(const char *str);

	int main(void)
	{
		printf("%d\n", ft_atoi("   42"));
		printf("%d\n", ft_atoi("-42"));
		printf("%d\n", ft_atoi("+42"));
		printf("%d\n", ft_atoi("  \t\n -123abc"));
		printf("%d\n", ft_atoi("0"));
		printf("%d\n", ft_atoi(""));
		printf("%d\n", ft_atoi("2147483647"));
		printf("%d\n", ft_atoi("-2147483648"));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '42\n-42\n42\n-123\n0\n0\n2147483647\n-2147483648')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_atoi output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_atoi"

clean:
	rm -rf $(BUILD_DIR)

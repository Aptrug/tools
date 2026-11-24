NAME		= ft_itoa
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
	char *ft_itoa(int nbr);

	int main(void)
	{
		printf("%s\n", ft_itoa(0));
		printf("%s\n", ft_itoa(42));
		printf("%s\n", ft_itoa(-42));
		printf("%s\n", ft_itoa(1));
		printf("%s\n", ft_itoa(-1));
		printf("%s\n", ft_itoa(INT_MAX));
		printf("%s\n", ft_itoa(INT_MIN));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '0\n42\n-42\n1\n-1\n2147483647\n-2147483648')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_itoa output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_itoa"

clean:
	rm -rf $(BUILD_DIR)

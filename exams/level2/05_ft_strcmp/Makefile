NAME		= ft_strcmp
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

	int ft_strcmp(char *s1, char *s2);

	char sign(int n)
	{
		if (n > 0)
			return ('+');
		if (n < 0)
			return ('-');
		return ('0');
	}

	int main(void)
	{
		printf("%c\n", sign(ft_strcmp("abc", "abc")));
		printf("%c\n", sign(ft_strcmp("abc", "abd")));
		printf("%c\n", sign(ft_strcmp("abc", "ab")));
		printf("%c\n", sign(ft_strcmp("ab", "abc")));
		printf("%c\n", sign(ft_strcmp("", "")));
		printf("%c\n", sign(ft_strcmp("Z", "a")));
		printf("%c\n", sign(ft_strcmp("a", "Z")));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '0\n-\n+\n-\n0\n-\n+')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strcmp output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_strcmp"

clean:
	rm -rf $(BUILD_DIR)

NAME		= ft_strcspn
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
	#include <stddef.h>

	size_t ft_strcspn(const char *s, const char *reject);

	int main(void)
	{
		printf("%lu\n", (unsigned long)ft_strcspn("hello world", "wor"));
		printf("%lu\n", (unsigned long)ft_strcspn("hello", "xyz"));
		printf("%lu\n", (unsigned long)ft_strcspn("hello", ""));
		printf("%lu\n", (unsigned long)ft_strcspn("", "abc"));
		printf("%lu\n", (unsigned long)ft_strcspn("abc", "a"));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '4\n5\n5\n0\n0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strcspn output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_strcspn"

clean:
	rm -rf $(BUILD_DIR)

NAME		= ft_strspn
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

	size_t ft_strspn(const char *s, const char *accept);

	int main(void)
	{
		printf("%lu\n", (unsigned long)ft_strspn("abcabc123", "abc"));
		printf("%lu\n", (unsigned long)ft_strspn("hello", "xyz"));
		printf("%lu\n", (unsigned long)ft_strspn("hello", ""));
		printf("%lu\n", (unsigned long)ft_strspn("", "abc"));
		printf("%lu\n", (unsigned long)ft_strspn("aaa", "a"));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '6\n0\n0\n0\n3')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strspn output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ft_strspn"

clean:
	rm -rf $(BUILD_DIR)
